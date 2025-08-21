#include "StraightDriver.h"

StraightDriver::StraightDriver(DriveController &driveController, int velocity) :
  Driver(driveController),
  velocity(velocity){
}

void StraightDriver::drive() {
  driveController.run_with_speed_and_direction(velocity, 0);
}
