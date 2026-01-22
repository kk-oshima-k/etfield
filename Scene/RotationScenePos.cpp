#include "RotationScenePos.h"
#include <vector>

RotationScenePos::RotationScenePos(AngleController &angleController, DriveController &driveController,
                               int angularVelocity,
                               int thresholdAngle) :
  rotationDriverPos(driveController, angularVelocity),
  angleDetector(angleController, driveController, thresholdAngle){
    init(&rotationDriverPos, {&angleDetector});
}

void RotationScenePos::enter_scene() {
  angleDetector.reset_angle();
}