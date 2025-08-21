#ifndef ANGLE_DETECTOR_H
#define ANGLE_DETECTOR_H

#include "Detector.h"
#include "../Device/DriveController.h"

using namespace spikeapi;

class AngleDetector : public Detector {
public:
  AngleDetector(const DriveController &driveController, int thresholdAngle);

  bool detect() override;

private:
  const DriveController &driveController;

  int thresholdAngle;
};

#endif // ANGLE_DETECTOR_H