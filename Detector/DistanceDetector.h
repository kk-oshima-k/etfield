#ifndef DISTANCE_DETECTOR_H
#define DISTANCE_DETECTOR_H

#include "Detector.h"
#include "../Device/DriveController.h"

using namespace spikeapi;

class DistanceDetector : public Detector {
public:
  DistanceDetector(const DriveController &driveController, int thresholdDistance);

  bool detect() override;

private:
  const DriveController &driveController;

  int thresholdDistance;
};

#endif // DISTANCE_DETECTOR_H