#include "RotationDriver.h"
#include <cstdio>
RotationDriver::RotationDriver(DriveController &driveController, int angularVelocity) :
  Driver(driveController),
  angularVelocity(angularVelocity){
}

void RotationDriver::drive() {
printf("%2d\n", angularVelocity);
  if(oldV != angularVelocity){
  driveController.run_with_power_and_direction(0, angularVelocity);
  oldV = angularVelocity;
  }
}
