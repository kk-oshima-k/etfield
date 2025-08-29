#ifndef STRAIGHT_SCENE_H
#define STRAIGHT_SCENE_H

#include "Scene.h"
#include "../Common/Common.h"
#include "../Device/DriveController.h"
#include "../Device/ColorSensorController.h"
#include "../Driver/StraightDriver.h"
#include "../Detector/ColorDetector.h"
#include "../Detector/DistanceDetector.h"

using namespace spikeapi;

class StraightScene : public Scene {
public:
  StraightScene(DriveController &driveController, const ColorSensorController &colorSensorController,
                 int velocity = 100,
                 LineColor color = LineColor::LINE_COLOR_BLUE,
                 int thresholdDistance = 100);

  void enter_scene() override;
  
protected:
  StraightDriver straightDriver;
  ColorDetector colorDetector;
  DistanceDetector distanceDetector;
};

#endif // STRAIGHT_SCENE_H