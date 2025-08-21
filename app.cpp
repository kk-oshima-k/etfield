#include "app.h"
#include <stdio.h>

#include "ETRobo/ETRobo.h"
#include "Device/DriveController.h"
#include "Device/ColorSensorController.h"
#include "ForceSensor.h"
#include "Clock.h"  

ETRobo *etrobo;
Clock clock;


using namespace spikeapi;

void etrobo_task(intptr_t exinf) {
  etrobo->process();
  ext_tsk();
}

void main_task(intptr_t unused) {
  const uint32_t duration = 100*1000;
  ForceSensor forceSensor(EPort::PORT_D);

  DriveController driveController;
  ColorSensorController colorSensorController;
  etrobo = new ETRobo(driveController, colorSensorController);

  sta_cyc(ETROBO_CYC);

  while (!forceSensor.isTouched()) {
      clock.sleep(duration);
  }

  stp_cyc(ETROBO_CYC);
  etrobo->terminate();
  ext_tsk(); // <5>
}

