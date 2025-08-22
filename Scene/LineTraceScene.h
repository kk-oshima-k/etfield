#ifndef LINE_TRACE_SCENE_H
#define LINE_TRACE_SCENE_H

#include "Scene.h"
#include "../Common/Common.h"
#include "../Device/DriveController.h"
#include "../Device/ColorSensorController.h"
#include "../Driver/LineTracer.h"
#include "../Detector/ColorDetector.h"
#include "../Detector/DistanceDetector.h"

using namespace spikeapi;

class LineTraceScene : public Scene {
public:
  LineTraceScene(DriveController &driveController, const ColorSensorController &colorSensorController,
                 int velocity = 100, bool rightEdge = false, const PIDParameters &pidParameters = {1.0, 0.1, 0.01}, int target = 127,
                 LineColor color = LineColor::LINE_COLOR_BLUE,
                 int thresholdDistance = 100);

protected:
  LineTracer lineTracer;
  ColorDetector colorDetector;
  DistanceDetector distanceDetector;
};

#endif // LINE_TRACE_SCENE_H