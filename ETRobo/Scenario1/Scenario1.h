#ifndef SCENARIO1_H
#define SCENARIO1_H

#include "../../Scenario/Scenario.h"
#include "../../Scene/LineTraceScene.h"
#include "../../Scene/StraightScene.h"
#include "../../Scene/RotationScene.h"
#include "../../Scene/FindBottleWithLineTraceScene.h"


class Scenario1Scene1 : public LineTraceScene {
public:
  Scenario1Scene1(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 100, bool rightEdge = true, const PIDParameters &pidParameters = {0.6, 0.02, 2.0}, int target = 54,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 50) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};

class Scenario1Scene2 : public FindBottleWithLineTraceScene {
public:
  Scenario1Scene2(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController,
          int velocity = 50, bool rightEdge = true, const PIDParameters &pidParameters = {0.6, 0.01, 1.0}, int target = 54,
          int thresholdDistance = 0,
          int bottleDistace = 200) :
    FindBottleWithLineTraceScene(driveController, colorSensorController, ultrasonicSensorController, velocity, rightEdge, pidParameters, target, thresholdDistance, bottleDistace) {}
};
class Scenario1Scene3 : public StraightScene {
public:
  Scenario1Scene3(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = -30,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = -10) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario1Scene4 : public RotationScene {
public:
  Scenario1Scene4(DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -30) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario1Scene5 : public StraightScene {
public:
  Scenario1Scene5(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 35) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario1Scene6 : public RotationScene {
public:
  Scenario1Scene6(DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 60) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario1Scene7 : public StraightScene {
public:
  Scenario1Scene7(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 0) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario1Scene8 : public RotationScene {
public:
  Scenario1Scene8(DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -25) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario1Scene9 : public LineTraceScene {
public:
  Scenario1Scene9(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 100, bool rightEdge = true, const PIDParameters &pidParameters = {0.6, 0.02, 2.0}, int target = 54,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 50) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};
class Scenario1Scene10 : public LineTraceScene {
public:
  Scenario1Scene10(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 60, bool rightEdge = true, const PIDParameters &pidParameters = {0.6, 0.01, 1.0}, int target = 54,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 32) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};
class Scenario1Scene11 : public LineTraceScene {
public:
  Scenario1Scene11(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 100, bool rightEdge = true, const PIDParameters &pidParameters = {0.6, 0.02, 2.0}, int target = 54,
          LineColor color = LineColor::LINE_COLOR_BLUE,
          int thresholdDistance = 0) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};



class Scenario1 : public Scenario {
public:
  Scenario1(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController);

  int process_scene() override;

  int switch_scene(int scene_index);

};

#endif // SCENARIO1_H
