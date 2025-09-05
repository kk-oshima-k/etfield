#ifndef DRIVE_CONTROLLER_H
#define DRIVE_CONTROLLER_H

#include <Motor.h>

#define PI 3.141592653589793238462643

using namespace spikeapi;

class DriveController {
public:
  DriveController();
  void run_with_motor_speeds(int left_speed, int right_speed);
  void run_with_motor_powers(int left_power, int right_power);
  void run_with_speed_and_direction(int velocity, int angular_velocity);
  void run_with_power_and_direction(int velocity, int angular_velocity);
  void stop();

  int get_distance() const;
  void reset_distance();

  int get_angle() const;
  void reset_angle();

private:
  int calculate_velocity2rotation(int velocity) const;

  int calculate_distance() const;
  int calculate_angle() const;

  static double degrees_to_radians(double degrees) {
    return degrees * PI / 180.0;
  }
  static double radians_to_degrees(double radians) {
    return radians * 180.0 / PI;
  }

private:
  Motor leftWheel;
  Motor rightWheel;

  const double wheel_diameter = 5.595; // cm
  const double wheel_base = 11.16; // cm
};

#endif // DRIVE_CONTROLLER_H