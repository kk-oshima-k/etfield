#ifndef ROTATION_SCENE_H
#define ROTATION_SCENE_H

#include "Scene.h"
#include "../Common/Common.h"
#include "../Device/DriveController.h"
#include "../Driver/RotationDriver.h"
#include "../Detector/AngleDetector.h"

using namespace spikeapi;

class RotationScene : public Scene {
public:
  RotationScene(DriveController &driveController,
                 int angularVelocity = 100,
                 int thresholdAngle = 90);

protected:
  RotationDriver rotationDriver;
  AngleDetector angleDetector;

};

#endif // ROTATION_SCENE_H