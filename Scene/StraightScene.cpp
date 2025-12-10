#include "StraightScene.h"
#include <vector>

StraightScene::StraightScene(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController,
                               int velocity, const PIDParameters &pidParameters,
                               LineColor color,
                               int thresholdDistance) :
  straightDriver(angleController, driveController, velocity, pidParameters),
  colorDetector(colorSensorController, color),
  angleDetector(angleController, driveController, 0),
  distanceDetector(driveController, thresholdDistance){
  init(&straightDriver, {&colorDetector, &distanceDetector});

}

void StraightScene::enter_scene() {
  distanceDetector.reset_distance();
  angleDetector.reset_angle();
}
