#include "StraightDriver.h"
#include <cstdio>

StraightDriver::StraightDriver(AngleController &angleController, DriveController &driveController, int velocity, const PIDParameters &pidParameters) :
  Driver(driveController),
  angleController(angleController),
  velocity(velocity),
  pidParameters(pidParameters){
}

void StraightDriver::drive() {
  int gain = calculate_PID_gain();
  driveController.run_with_power_and_direction(velocity, gain);
  printf("%3d\n", driveController.get_distance());
  
}

int StraightDriver::calculate_PID_gain() {
  AngleController::myxyz xyz = angleController.getAngle();
  error1 += atan(sin(DriveController::degrees_to_radians(xyz.z)) * driveController.get_speed() * 50 * 0.001);
  
  float error2 = xyz.z;

  float error = (0.3 * error1) + (0.7 * error2);
  printf("e %f\nz %f\nspeed %f", error, xyz.z, driveController.get_speed());

  int output = pidParameters.kp * -error;

  return output;
}