#ifndef ULTRASONIC_DETECTOR_H
#define ULTRASONIC_DETECTOR_H

#include "Detector.h"
#include "../Device/UltrasonicSensorController.h"

using namespace spikeapi;

class UltrasonicDetector : public Detector {
public:
  UltrasonicDetector(UltrasonicSensorController &ultrasonicSensorController, int thresholdDistance);

  bool detect() override;

private:
  UltrasonicSensorController &ultrasonicSensorController;

  int thresholdDistance;
};

#endif // ULTRASONIC_DETECTOR_H