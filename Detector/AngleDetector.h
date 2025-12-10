#ifndef ANGLE_DETECTOR_H
#define ANGLE_DETECTOR_H

#include "Detector.h"
#include "../Device/AngleController.h"
#include "../Device/DriveController.h"

using namespace spikeapi;

class AngleDetector : public Detector {
public:
  AngleDetector(AngleController &angleController, DriveController &driveController, int thresholdAngle);

  void reset_angle();
  bool detect() override;

private:
  AngleController angleController;
  DriveController driveController;
  

  int thresholdAngle;
};

#endif // ANGLE_DETECTOR_H