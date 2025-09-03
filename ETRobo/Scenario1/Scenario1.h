#ifndef SCENARIO1_H
#define SCENARIO1_H

#include "../../Scenario/Scenario.h"
#include "../../Scene/LineTraceScene.h"
#include "../../Scene/StraightScene.h"
#include "../../Scene/RotationScene.h"
#include "../../Scene/FindBottleWithLineTraceScene.h"

class Scenario1Scene1 : public FindBottleWithLineTraceScene {
public:
  Scenario1Scene1(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController,
          int velocity = 20, bool rightEdge = false, const PIDParameters &pidParameters = {0.25, 0.005*0, 0.25*0}, int target = 525,
          LineColor color = LineColor::LINE_COLOR_NONE,
          int thresholdDistance = 157,
          int bottleDistace = 14) :
    FindBottleWithLineTraceScene(driveController, colorSensorController, ultrasonicSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance, bottleDistace) {}
};
class Scenario1Scene2 : public RotationScene {
public:
  Scenario1Scene2(DriveController &driveController, int angularVelocity = 20, int thresholdAngle = -30) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario1Scene3 : public StraightScene {
public:
  Scenario1Scene3(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 20,
          LineColor color = LineColor::LINE_COLOR_NONE,
          int thresholdDistance = 35) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario1Scene4 : public RotationScene {
public:
  Scenario1Scene4(DriveController &driveController, int angularVelocity = 20, int thresholdAngle = 120) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario1Scene5 : public StraightScene {
public:
  Scenario1Scene5(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 20,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 0) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario1Scene6 : public RotationScene {
public:
  Scenario1Scene6(DriveController &driveController, int angularVelocity = 20, int thresholdAngle = 30) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario1Scene7 : public LineTraceScene {
public:
  Scenario1Scene7(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 20, bool rightEdge = false, const PIDParameters &pidParameters = {1.0, 0.1, 0.01}, int target = 127,
          LineColor color = LineColor::LINE_COLOR_BLUE,
          int thresholdDistance = 320) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};

class Scenario1 : public Scenario {
public:
  Scenario1(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController);

  int process_scene() override;

  int switch_scene(int scene_index);

};

#endif // SCENARIO1_H