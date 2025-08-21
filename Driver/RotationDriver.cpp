#include "RotationDriver.h"

RotationDriver::RotationDriver(DriveController &driveController, int angularVelocity) :
  Driver(driveController),
  angularVelocity(angularVelocity){
}

void RotationDriver::drive() {
  driveController.run_with_speed_and_direction(0, angularVelocity);
}
