#ifndef ROTATION_SCENE_POS_H
#define ROTATION_SCENE_POS_H

#include "Scene.h"
#include "../Common/Common.h"
#include "../Device/DriveController.h"
#include "../Device/AngleController.h"
#include "../Driver/RotationDriverPos.h"
#include "../Detector/AngleDetector.h"

using namespace spikeapi;

class RotationScenePos : public Scene {
public:
  RotationScenePos(AngleController &angleController, DriveController &driveController,
                 int angularVelocity = 100,
                 int thresholdAngle = 90);

  void enter_scene() override;

protected:
  RotationDriverPos rotationDriverPos;
  AngleDetector angleDetector;

};

#endif // ROTATION_SCENE_POS_H