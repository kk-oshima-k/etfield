#include "DistanceDetector.h"

DistanceDetector::DistanceDetector(DriveController &driveController, int thresholdDistance) :
  Detector(),
  driveController(driveController),
  thresholdDistance(thresholdDistance) {
}

void DistanceDetector::reset_distance() {
  driveController.reset_distance();
}

bool DistanceDetector::detect() {
  int distance = driveController.get_distance();
  return thresholdDistance < distance ; // Return true if detected within threshold, else false
}

