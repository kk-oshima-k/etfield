#include "AngleDetector.h"
#include <cstdio>

AngleDetector::AngleDetector(AngleController &angleController, int thresholdAngle) :
  Detector(),
  angleController(angleController),
  thresholdAngle(thresholdAngle) {
}

void AngleDetector::reset_angle() {
  angleController.resetAngle();
}

bool AngleDetector::detect() {
  AngleController::myxyz xyz = angleController.getAngle();
  printf("angle %f\n", xyz.z);
  
  if (thresholdAngle > 0){
    return thresholdAngle < xyz.z ; // Return true if detected within threshold, else false
  } else {
    return xyz.z < thresholdAngle ; // Return true if detected within negative threshold, else false
  }
}
