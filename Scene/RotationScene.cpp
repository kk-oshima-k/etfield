#include "RotationScene.h"
#include <vector>

RotationScene::RotationScene(AngleController &angleController, DriveController &driveController,
                               int angularVelocity,
                               int thresholdAngle) :
  rotationDriver(driveController, angularVelocity),
  angleDetector(angleController, driveController, thresholdAngle){
    init(&rotationDriver, {&angleDetector});
}

void RotationScene::enter_scene() {
  angleDetector.reset_angle();
}