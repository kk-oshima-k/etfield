#ifndef GATE_SCENE_H
#define GATE_SCENE_H

#include "Scene.h"
#include "../Common/Common.h"
#include "../Device/DriveController.h"
#include "../Device/ColorSensorController.h"
#include "../Driver/LineTracer.h"
#include "../Detector/ColorDetector.h"
#include "../Detector/DistanceDetector.h"

using namespace spikeapi;

extern int camera_find;

class GateScene : public Scene {
public:
  GateScene(DriveController &driveController, const ColorSensorController &colorSensorController,
             int velocity = 100,
             LineColor color = LineColor::LINE_COLOR_BLUE,
             int thresholdDistance = 100);

  void enter_scene() override;

protected:
  LineTracer lineTracer;
  ColorDetector colorDetector;
  DistanceDetector distanceDetector;
  int count;
};

#endif // GATE_SCENE_H