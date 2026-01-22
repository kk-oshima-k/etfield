#ifndef ROTATION_DRIVER_POS_H
#define ROTATION_DRIVER_POS_H

#include "Driver.h"
#include "../Common/Common.h"
#include "../Device/DriveController.h"

using namespace spikeapi;

class RotationDriverPos : public Driver {
public:
  RotationDriverPos(DriveController &driveController, int angularVelocity);

  void drive() override;

private:
  int angularVelocity;
  int oldV;
};

#endif // ROTATION_DRIVER_POS_H