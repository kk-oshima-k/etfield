#include "AngleDetector.h"
#include <cstdio>

AngleDetector::AngleDetector(AngleController &angleController, DriveController &driveController, int thresholdAngle) :
  Detector(),
  angleController(angleController),
  driveController(driveController), 
  thresholdAngle(thresholdAngle) {
}

void AngleDetector::reset_angle() {
  angleController.resetAngle();
  driveController.reset_angle();
}

bool AngleDetector::detect() {
  AngleController::myxyz xyz = angleController.getAngle();
  float drive_z = driveController.get_angle();

  float angle = (0.6 * xyz.z) + (0.4 * drive_z);
  printf("angle %d\n", angle);
  
  if (thresholdAngle > 0){
    return thresholdAngle < angle ; // Return true if detected within threshold, else false
  } else {
    return angle < thresholdAngle ; // Return true if detected within negative threshold, else false
  }
}
