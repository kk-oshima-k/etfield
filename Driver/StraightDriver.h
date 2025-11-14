#ifndef STRAIGHT_DRIVER_H
#define STRAIGHT_DRIVER_H

#include "Driver.h"
#include "../Common/Common.h"
#include "../Device/DriveController.h"
#include "../Device/AngleController.h"

using namespace spikeapi;

class StraightDriver : public Driver {
public:
  StraightDriver(AngleController &angleController, DriveController &driveController, int velocity, const PIDParameters &pidParameters);

  void drive() override;

private:
  int calculate_PID_gain();

private:
  AngleController angleController;
  PIDParameters pidParameters;

  int velocity;
  float error1 = 0.0;
};

#endif // STRAIGHT_DRIVER_H