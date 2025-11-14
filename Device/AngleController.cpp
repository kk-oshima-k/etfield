#include "AngleController.h"
#include <cmath>
#include <cstdio>

#define PI 3.141592653589793238462643

AngleController::AngleController() :
  IMU(),
  xyz{0.0, 0.0, 0.0},
  dev{0.0}
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
  // xyz.x += (ang.x * cos(pitch) + ang.z * sin(pitch)) * 50 * 0.001;
  // xyz.y += ang.y * 50 * 0.001;
  
  float zaxis = (ang.x * cos(pitch) - ang.z * sin(pitch)) * 50 * 0.001;
  if(std::fabs(zaxis) > 0.05){
    z1 += zaxis;
  }
  // テスト用
  // z1 +=(ang.x * cos(pitch) - ang.z * sin(pitch)) * 50 * 0.001;

  // テスト用
  // float zdiff = std::fabs(z1 - ano_z);
  // if(zdiff > zdiffmax){
  //   zdiffmax = zdiff;
  // }
  // printf("zdiffmax %f\n", zdiffmax);
  // ano_z = z1;
  int z2 = driveController.get_angle();

  xyz.z = 0.5 * z1 + 0.5 * z2;

  return xyz;
}

void AngleController::resetAngle() {
  xyz.x = 0.0;
  xyz.y = 0.0;
  xyz.z = 0.0;
}