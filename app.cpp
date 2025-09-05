#include "app.h"
#include <stdio.h>

#include "ETRobo/ETRobo.h"
#include "Device/DriveController.h"
#include "Device/ColorSensorController.h"
#include "Device/UltrasonicSensorController.h"
#include "ForceSensor.h"
#include "Clock.h"  

#include <cstdio>
#include <ctime>

ETRobo *etrobo;

#ifdef MAKE_RASPIKE // not sim
FILE *fp;
#endif

using namespace spikeapi;

void etrobo_task(intptr_t exinf) {
  etrobo->process();
  ext_tsk();
}

void main_task(intptr_t unused) {
  const uint32_t duration = 100*1000;
  ForceSensor forceSensor(EPort::PORT_D);
  
  Clock clock;

  DriveController driveController;
  ColorSensorController colorSensorController;
  UltrasonicSensorController ultrasonicSensorController;
  etrobo = new ETRobo(driveController, colorSensorController, ultrasonicSensorController);
  etrobo->initialize();

  sta_cyc(ETROBO_CYC);

  char datetime[64];
  char path[256];
#ifdef MAKE_RASPIKE // not sim
  time_t t = time(NULL);
  strftime(datetime, sizeof(datetime), "%Y%m%d_%H%M%S", localtime(&t));
  sprintf(path, "/home/kklab/RasPike-ART/sdk/workspace/etfield/log/%s.txt", datetime);
  printf("test:%s\n", path);
  fp = fopen(path, "a");
#endif

  while (!forceSensor.isTouched()) {
      clock.sleep(duration);
  }

  stp_cyc(ETROBO_CYC);
  etrobo->terminate();
#ifdef MAKE_RASPIKE // not sim
  fclose(fp);
#endif
  ext_tsk(); // <5>
}

