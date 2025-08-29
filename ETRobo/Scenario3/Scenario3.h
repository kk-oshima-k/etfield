#ifndef SCENARIO3_H
#define SCENARIO3_H

#include "../../Scenario/Scenario.h"
#include "../../Scene/LineTraceScene.h"
#include "../../Scene/StraightScene.h"
#include "../../Scene/RotationScene.h"

class Scenario3Scene1 : public LineTraceScene {
public:
  Scenario3Scene1(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 300, bool rightEdge = false, const PIDParameters &pidParameters = {0.25, 0.005*0, 0.25*0}, int target = 525,
          LineColor color = LineColor::LINE_COLOR_BLUE,
          int thresholdDistance = 100) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};
class Scenario3Scene2 : public RotationScene {
public:
  Scenario3Scene2(DriveController &driveController, int angularVelocity = -30, int thresholdAngle = -320) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene3 : public StraightScene {
public:
  Scenario3Scene3(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 100,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 100) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario2Scene4 : public RotationScene {
public:
  Scenario3Scene4(DriveController &driveController, int angularVelocity = 100, int thresholdAngle = 90) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};



class Scenario3 : public Scenario {
public:
  Scenario3(DriveController &driveController, const ColorSensorController &colorSensorController);

  int process_scene() override;

  int switch_scene(int scene_index);

};




#endif // SCENARIO3_H