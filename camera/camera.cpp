#include <cstdio>
#include <ctime>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

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
    }
}
