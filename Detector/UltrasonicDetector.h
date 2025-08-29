#ifndef ULTRASONIC_DETECTOR_H
#define ULTRASONIC_DETECTOR_H

#include "Detector.h"
#include "../Device/UltrasonicSensorController.h"

using namespace spikeapi;

class UltrasonicDetector : public Detector {
public:
  UltrasonicDetector(DriveController &driveController, int thresholdDistance);

  bool detect() override;

private:
  DriveController &driveController;

  int thresholdDistance;
};

#endif // ULTRASONIC_DETECTOR_H