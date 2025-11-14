#ifndef ANGLE_DETECTOR_H
#define ANGLE_DETECTOR_H

#include "Detector.h"
#include "../Device/AngleController.h"

using namespace spikeapi;

class AngleDetector : public Detector {
public:
  AngleDetector(AngleController &angleController, int thresholdAngle);

  void reset_angle();
  bool detect() override;

private:
  AngleController angleController;

  int thresholdAngle;
};

#endif // ANGLE_DETECTOR_H