#ifndef DRIVER_H
#define DRIVER_H

#include "../Device/DriveController.h"

class Driver {
protected:
  Driver(DriveController &driveController);

public:
  virtual void drive() = 0;
  void stop();

protected:
  DriveController &driveController;
};

#endif // DRIVER_H