#ifndef STRAIGHT_DRIVER_H
#define STRAIGHT_DRIVER_H

#include "Driver.h"
#include "../Common/Common.h"
#include "../Device/DriveController.h"

using namespace spikeapi;

class StraightDriver : public Driver {
public:
  StraightDriver(DriveController &driveController, int velocity);

  void drive() override;

private:
  int velocity;
};

#endif // STRAIGHT_DRIVER_H