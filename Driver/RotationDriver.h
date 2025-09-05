#ifndef ROTATION_DRIVER_H
#define ROTATION_DRIVER_H

#include "Driver.h"
#include "../Common/Common.h"
#include "../Device/DriveController.h"

using namespace spikeapi;

class RotationDriver : public Driver {
public:
  RotationDriver(DriveController &driveController, int angularVelocity);

  void drive() override;

private:
  int angularVelocity;
  int oldV;
};

#endif // ROTATION_DRIVER_H