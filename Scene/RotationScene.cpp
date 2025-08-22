#include "RotationScene.h"
#include <vector>

RotationScene::RotationScene(DriveController &driveController,
                               int angularVelocity,
                               int thresholdAngle) :
  rotationDriver(driveController, angularVelocity),
  angleDetector(driveController, thresholdAngle){
    init(&rotationDriver, {&angleDetector});
}

void RotationScene::enter_scene() {
  angleDetector.reset_angle();
}
