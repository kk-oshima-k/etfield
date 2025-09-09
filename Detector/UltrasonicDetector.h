#ifndef ULTRASONIC_DETECTOR_H
#define ULTRASONIC_DETECTOR_H

#include "Detector.h"
#include "../Device/UltrasonicSensorController.h"

using namespace spikeapi;

class UltrasonicDetector : public Detector {
public:
  UltrasonicDetector(const UltrasonicSensorController &ultrasonicSensorController, int bottleDistance);

  bool detect() override;

private:
  const UltrasonicSensorController &ultrasonicSensorController;

  int bottleDistance;
};

#endif // ULTRASONIC_DETECTOR_H