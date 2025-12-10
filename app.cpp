#include "app.h"
#include "camera/camera.h"

#include "ETRobo/ETRobo.h"
#include "Device/AngleController.h"
#include "Device/DriveController.h"
#include "Device/ColorSensorController.h"
#include "Device/UltrasonicSensorController.h"
#include "ForceSensor.h"
#include "Clock.h"  

#include <cstdio>
#include <ctime>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

ETRobo *etrobo;

#ifdef MAKE_RASPIKE // not sim
FILE *fp;
#endif

using namespace spikeapi;

int camera_find = 0;
int center_x = 0;
int width_between = 0;

void etrobo_task(intptr_t exinf) {
    etrobo->process();
    ext_tsk();
}

void main_task(intptr_t unused) {
    const uint32_t duration = 100*1000;
    ForceSensor forceSensor(EPort::PORT_D);
    
    Clock clock;

    AngleController angleController;
    DriveController driveController;
    ColorSensorController colorSensorController;
    UltrasonicSensorController ultrasonicSensorController;
    etrobo = new ETRobo(angleController, driveController, colorSensorController, ultrasonicSensorController);

    char datetime[64];
#ifdef MAKE_RASPIKE // not sim
    char path[256];
    time_t t = time(NULL);
    strftime(datetime, sizeof(datetime), "%Y%m%d_%H%M%S", localtime(&t));
    sprintf(path, "/home/kklab/RasPike-ART/sdk/workspace/etfield/log/%s.txt", datetime);
    printf("test:%s\n", path);
    fp = fopen(path, "a");
#endif
    char mes[256];
    time_t mest = time(NULL);
    strftime(datetime, sizeof(datetime), "%Y%m%d_%H%M%S", localtime(&mest));
    sprintf(mes, "Start! %s\n", datetime);
    printf("%s", mes);
#ifdef MAKE_RASPIKE // not sim
    fprintf(fp, "%s", mes);
#endif
    etrobo->initialize();
    initialize_camera();

    sta_cyc(CAMERA_CYC);

#ifdef MAKE_RASPIKE // not sim
    while (!forceSensor.isTouched()) {
        clock.sleep(duration);
    }
    while (forceSensor.isTouched()) {
        clock.sleep(duration);
    }

#endif

    sta_cyc(ETROBO_CYC);

#ifdef MAKE_RASPIKE // not sim
    while (!forceSensor.isTouched()) {
        clock.sleep(duration);
    }
#endif

    stp_cyc(CAMERA_CYC);
    stp_cyc(ETROBO_CYC);
    etrobo->terminate();
    close_camera();
#ifdef MAKE_RASPIKE // not sim
    fclose(fp);
#endif
    ext_tsk(); // <5>
}

int sock;
char buf[256];

void initialize_camera(void){
    struct sockaddr_in addr;
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(12345);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(sock, (struct sockaddr *)&addr, sizeof(addr));

    int val = 1;
    ioctl(sock, FIONBIO, &val);
}

void close_camera(void){
    close(sock);
}

void camera_task(intptr_t exinf) {
    int n = recv(sock, buf, sizeof(buf), 0);
    if (n < 1){
        if(errno == EAGAIN){
            printf("recv no mes.\n");
            return;
        }else{
            // ERROR
            return;
        }
    }else{
        printf("recv: %s\n", buf);
        char *s = buf, *e;
        if(*s == '1'){
            s = strchr(s, ',');
            if(s == NULL){
                // error
                return;
            }
            s += 1;
            e = strchr(s, ',');
            if(e == NULL){
                // error
                return;
            }
            *e = '\0';
            int x = atoi(s);
            s = e+1;
            int w = atoi(s);
            camera_find = 1;
            center_x = x;
            width_between = w;
        }
    }
}
