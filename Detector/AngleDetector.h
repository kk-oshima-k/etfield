#ifndef ANGLE_DETECTOR_H
#define ANGLE_DETECTOR_H

#include "Detector.h"
#include "../Device/DriveController.h"

using namespace spikeapi;

class AngleDetector : public Detector {
public:
  AngleDetector(DriveController &driveController, int thresholdAngle);

  void reset_angle();
  bool detect() override;

private:
  DriveController &driveController;

  int thresholdAngle;
};

#endif // ANGLE_DETECTOR_H