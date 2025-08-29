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
  if (thresholdDistance > 0){
    return thresholdDistance < distance ; // Return true if detected within threshold, else false
  } else if(thresholdDistance < 0){
    return distance < thresholdDistance ; // Return true if detected within threshold, else false
  } else {
    return true; // thresholdDistance == 0 has no restrictions
  }
}

