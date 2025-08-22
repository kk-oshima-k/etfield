#include "LineTracer.h"
#include <cstdio>

LineTracer::LineTracer(DriveController &driveController, const ColorSensorController &colorSensorController, int velocity, bool edge, const PIDParameters &pidParameters, int target) :
  Driver(driveController),
  colorSensorController(colorSensorController),
  velocity(velocity),
  edge(edge),
  pidParameters(pidParameters),
  target(target),
  previousError(0),
  integral(0){
#ifndef MAKE_RASPIKE
  simup = false;
#endif
}

void LineTracer::drive() {
  int gain = calculate_PID_gain();
  if (edge == 0) { // Left edge
    driveController.run_with_speed_and_direction(velocity, gain);
  } else { // Right edge
    driveController.run_with_speed_and_direction(velocity, -gain);
   }
}

int LineTracer::calculate_PID_gain() {
  ColorSensorController::HSV hsv;
  colorSensorController.getHSV(hsv);
  ColorSensorController::RGB rgb;
  colorSensorController.getRGB(rgb);
#ifndef MAKE_RASPIKE
  if(simup == false){
    if(hsv.v == 0){
      printf("waiting for initialize...\n");
      return 0;
    }else{
      simup = true;
    }
  }
#endif

  
  // 現在の偏差を計算 今は明度を利用　TODO: 色相や彩度を利用する場合は適宜変更
  int error = target - hsv.v;
  
  // 積分項を更新（積分の蓄積）
  integral += error;
  
  // 微分項を計算
  int derivative = error - previousError;
  
  // PID制御の出力を計算
  int output = pidParameters.kp * error + pidParameters.ki * integral + pidParameters.kd * derivative;
  
  printf("%3d %3d %3d %3d %3d %3d %4d %4d %d\n",rgb.r, rgb.g, rgb.b, hsv.h, hsv.s, hsv.v, error, derivative, integral);
  // 前回の偏差を保存
  previousError = error;
  
  return output;
}
