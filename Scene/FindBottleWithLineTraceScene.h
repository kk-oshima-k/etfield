#ifndef FIND_BOTTLE_WITH_LINE_TRACE_SCENE_H
#define FIND_BOTTLE_WITH_LINE_TRACE_SCENE_H

#include "Scene.h"
#include "../Common/Common.h"
#include "../Device/DriveController.h"
#include "../Device/ColorSensorController.h"
#include "../Device/UltrasonicSensorController.h"
#include "../Driver/LineTracer.h"
#include "../Detector/ColorDetector.h"
#include "../Detector/DistanceDetector.h"
#include "../Detector/UltrasonicDetector.h"

using namespace spikeapi;

class FindBottleWithLineTraceScene : public Scene {
public:
  FindBottleWithLineTraceScene(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController, 
                               int velocity = 100, bool rightEdge = false, const PIDParameters &pidParameters = {1.0, 0.1, 0.01}, int target = 127,
                               LineColor color = LineColor::LINE_COLOR_NONE,
                               int thresholdDistance = 100
                               int bottleDistance = 100);

  void enter_scene() override;

protected:
  LineTracer lineTracer;
  DistanceDetector distanceDetector;
  UltrasonicDetector ultrasonicDetector;
};

#endif // FIND_BOTTLE_WITH_LINE_TRACE_SCENE_H