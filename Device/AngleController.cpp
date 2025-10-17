#include "AngleController.h"
#include <cmath>
#include <cstdio>

#define PI 3.141592653589793238462643

AngleController::AngleController() :
  IMU(),
  xyz{0.0, 0.0, 0.0}
  {
}

AngleController::myxyz AngleController::getAngle() {
  AngularVelocity ang;
  getAngularVelocity(ang);
  Acceleration acc;
  getAcceleration(acc);

  float pitch = atan2(-acc.x, sqrt(acc.y * acc.y + acc.z * acc.z));
  float pitch_deg = pitch * 180.0 / PI;
  printf("pitch %d\n", pitch_deg);

  // xyは仮
  xyz.x += (ang.x * cos(pitch) + ang.z * sin(pitch)) * 50 * 0.001;
  xyz.y += ang.y * 50 * 0.001;
  float zaxis = (ang.x * cos(pitch) - ang.z * sin(pitch)) * 50 * 0.001;
  if(std::fabs(zaxis) > 0.05){
    xyz.z += zaxis;
  }

  
  //テスト用
  // float zdiff = std::fabs(xyz.z - ano_z);
  // if(zdiff > zdiffmax){
  //   zdiffmax = zdiff;
  // }
  // printf("zdiffmax %f\n", zdiffmax);
  // ano_z = xyz.z;

  return xyz;
}

void AngleController::resetAngle() {
  xyz.x = 0.0;
  xyz.y = 0.0;
  xyz.z = 0.0;
}