#ifndef STRAIGHT_SCENE_H
#define STRAIGHT_SCENE_H

#include "Scene.h"
#include "../Common/Common.h"
#include "../Device/AngleController.h"
#include "../Device/DriveController.h"
#include "../Device/ColorSensorController.h"
#include "../Driver/StraightDriver.h"
#include "../Detector/AngleDetector.h"
#include "../Detector/Detector.h"
#include "../Detector/ColorDetector.h"
#include "../Detector/DistanceDetector.h"

using namespace spikeapi;

class StraightScene : public Scene {
public:
  StraightScene(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController,
                 int velocity = 100, const PIDParameters &pidParameters = {1.0, 0.1, 0.01},
                 LineColor color = LineColor::LINE_COLOR_BLUE,
                 int thresholdDistance = 100);

  void enter_scene() override;
  
protected:
  StraightDriver straightDriver;
  AngleDetector angleDetector;
  ColorDetector colorDetector;
  DistanceDetector distanceDetector;
};

#endif // STRAIGHT_SCENE_H