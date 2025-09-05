#include "StraightDriver.h"
#include <cstdio>

StraightDriver::StraightDriver(DriveController &driveController, int velocity) :
  Driver(driveController),
  velocity(velocity){
}

void StraightDriver::drive() {
  driveController.run_with_power_and_direction(velocity, 0);
  printf("%3d\n", driveController.get_distance());
}
