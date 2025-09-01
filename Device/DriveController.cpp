#include "DriveController.h"
#include <cstdio>

extern FILE *fp;

DriveController::DriveController() :
  leftWheel(EPort::PORT_B, Motor::EDirection::COUNTERCLOCKWISE, true),
  rightWheel(EPort::PORT_A, Motor::EDirection::CLOCKWISE, true){

}

/**
 * int left_speed : °/s
 * int right_speed : °/s
 */
void DriveController::run_with_motor_speeds(int left_speed, int right_speed) {
  leftWheel.setSpeed(left_speed);
  rightWheel.setSpeed(right_speed);

}

/**
 * int velocity : cm/s
 * int angular_velocity : °/s
 */
void DriveController::run_with_speed_and_direction(int velocity, int angular_velocity) {
  int left_speed = calculate_velocity2rotation(velocity) - angular_velocity;
  int right_speed = calculate_velocity2rotation(velocity) + angular_velocity;

  run_with_motor_speeds(left_speed, right_speed);
}
void DriveController::stop() {
  leftWheel.stop();
  rightWheel.stop();
}

int DriveController::get_distance() const{
  return calculate_distance();
}
void DriveController::reset_distance(){
  leftWheel.resetCount();
  rightWheel.resetCount();
}

int DriveController::get_angle() const{
  return calculate_angle();
}

void DriveController::reset_angle(){
  leftWheel.resetCount();
  rightWheel.resetCount();
}

int DriveController::calculate_velocity2rotation(int velocity) const{
  return radians_to_degrees(velocity / (wheel_diameter / 2));
}

int DriveController::calculate_distance() const{
  return wheel_diameter / 2.0 * degrees_to_radians((leftWheel.getCount() + rightWheel.getCount()) / 2.0);
}

int DriveController::calculate_angle() const{

  int angle = wheel_diameter * degrees_to_radians(rightWheel.getCount() - leftWheel.getCount()) / wheel_base;
  printf("%3d\n", angle);
  fprintf(fp, "%3d\n", angle);
  return angle;
}
