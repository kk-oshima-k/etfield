#include "LineTraceScene.h"
#include <vector>

LineTraceScene::LineTraceScene(DriveController &driveController, const ColorSensorController &colorSensorController,
                               int velocity, bool edge, const PIDParameters &pidParameters, int target,
                               LineColor color,
                               int thresholdDistance) :
  lineTracer(driveController, colorSensorController, velocity, edge, pidParameters, target),
  colorDetector(colorSensorController, color),
  distanceDetector(driveController, thresholdDistance){
    init(&lineTracer, {&colorDetector, &distanceDetector});
}

