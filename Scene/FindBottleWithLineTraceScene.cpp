#include "FindBottleWithLineTraceScene.h"
#include <vector>

FindBottleWithLineTraceScene::FindBottleWithLineTraceScene(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController,
                                                           int velocity, bool rightEdge, const PIDParameters &pidParameters, int target,
                                                           LineColor color,
                                                           int thresholdDistance,
                                                           int bottleDistance) :
  lineTracer(driveController, colorSensorController, velocity, rightEdge, pidParameters, target),
  distanceDetector(driveController, thresholdDistance),
  ultrasonicDetector(ultrasonicSensorController, bottleDistance)
    {
    init(&lineTracer, {&ultrasonicDetector, &distanceDetector});
}

void FindBottleWithLineTraceScene::enter_scene() {
  distanceDetector.reset_distance();
} 