#include "StraightScene.h"
#include <vector>

StraightScene::StraightScene(DriveController &driveController, const ColorSensorController &colorSensorController,
                               int velocity,
                               LineColor color,
                               int thresholdDistance) :
  straightDriver(driveController, velocity),
  colorDetector(colorSensorController, color),
  distanceDetector(driveController, thresholdDistance){
  init(&straightDriver, {&colorDetector, &distanceDetector});

}

