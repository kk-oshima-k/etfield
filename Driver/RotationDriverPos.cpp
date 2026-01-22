#include "RotationDriverPos.h"
#include <cstdio>
RotationDriverPos::RotationDriverPos(DriveController &driveController, int angularVelocity) :
  Driver(driveController),
  angularVelocity(angularVelocity){
}

void RotationDriverPos::drive() {
printf("%2d\n", angularVelocity);
  if(oldV != angularVelocity){
  driveController.run_with_power_and_Rotation(-angularVelocity, angularVelocity);
  oldV = angularVelocity;
  }
}
