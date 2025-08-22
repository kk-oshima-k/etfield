#include "AngleDetector.h"

AngleDetector::AngleDetector(DriveController &driveController, int thresholdAngle) :
  Detector(),
  driveController(driveController),
  thresholdAngle(thresholdAngle) {
}

void AngleDetector::reset_angle() {
  driveController.reset_angle();
}

bool AngleDetector::detect() {
  int angle = driveController.get_angle();
  
  if (thresholdAngle > 0){
    return thresholdAngle < angle ; // Return true if detected within threshold, else false
  } else {
    return angle < thresholdAngle ; // Return true if detected within negative threshold, else false
  }
}
