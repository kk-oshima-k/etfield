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
          int velocity = 50, bool rightEdge = true, const PIDParameters &pidParameters = {0.6, 0.005, 1.0}, int target = 54,
          int thresholdDistance = 25,
          int bottleDistace = 200) :
    FindBottleWithLineTraceScene(driveController, colorSensorController, ultrasonicSensorController, velocity, rightEdge, pidParameters, target, thresholdDistance, bottleDistace) {}
};
class Scenario1Scene2 : public StraightScene {
public:
  Scenario1Scene2(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = -30,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = -10) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario1Scene3 : public RotationScene {
public:
  Scenario1Scene3(DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -30) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario1Scene4 : public StraightScene {
public:
  Scenario1Scene4(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 35) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario1Scene5 : public RotationScene {
public:
  Scenario1Scene5(DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 60) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario1Scene6 : public StraightScene {
public:
  Scenario1Scene6(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 30) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario1Scene7 : public RotationScene {
public:
  Scenario1Scene7(DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -25) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario1Scene8 : public LineTraceScene {
public:
  Scenario1Scene8(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, bool rightEdge = true, const PIDParameters &pidParameters = {0.6, 0.005, 1.0}, int target = 54,
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
