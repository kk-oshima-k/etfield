#include "DistanceDetector.h"

DistanceDetector::DistanceDetector(const DriveController &driveController, int thresholdDistance) :
  Detector(),
  driveController(driveController),
  thresholdDistance(thresholdDistance) {
}

bool DistanceDetector::detect() {
  int distance = driveController.get_distance();
  return thresholdDistance < distance ; // Return true if detected within threshold, else false
}
