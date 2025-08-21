#include "AngleDetector.h"

AngleDetector::AngleDetector(const DriveController &driveController, int thresholdAngle) :
  Detector(),
  driveController(driveController),
  thresholdAngle(thresholdAngle) {
}

bool AngleDetector::detect() {
  int angle = driveController.get_angle();
  
  if (thresholdAngle > 0){
    return thresholdAngle < angle ; // Return true if detected within threshold, else false
  } else {
    return angle < thresholdAngle ; // Return true if detected within negative threshold, else false
  }
}
