#ifndef SCENARIO3_H
#define SCENARIO3_H

#include "../../Scenario/Scenario.h"
#include "../../Scene/LineTraceScene.h"
#include "../../Scene/StraightScene.h"
#include "../../Scene/RotationScene.h"
#include "../../Scene/FindBottleWithLineTraceScene.h"

class Scenario3Scene1 : public FindBottleWithLineTraceScene {
public:
  Scenario3Scene1(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController,
          int velocity = 50, bool rightEdge = true, const PIDParameters &pidParameters = {0.6, 0.01, 1.0}, int target = 54,
          int thresholdDistance = 0,
          int bottleDistace = 200) :
    FindBottleWithLineTraceScene(driveController, colorSensorController, ultrasonicSensorController, velocity, rightEdge, pidParameters, target, thresholdDistance, bottleDistace) {}
};
class Scenario3Scene2 : public StraightScene {
public:
  Scenario3Scene2(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 13) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene3 : public RotationScene {
public:
  Scenario3Scene3(DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 85) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene4 : public StraightScene {
public:
  Scenario3Scene4(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 80,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 150) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene5 : public StraightScene {
public:
  Scenario3Scene5(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = -35,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = -20) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene6 : public RotationScene {
public:
  Scenario3Scene6(DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -90) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene7 : public StraightScene {
public:
  Scenario3Scene7(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 45) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene8 : public RotationScene {
public:
  Scenario3Scene8(DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 45) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene9 : public StraightScene {
public:
  Scenario3Scene9(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 0) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene10 : public RotationScene {
public:
  Scenario3Scene10(DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -45) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene11 : public FindBottleWithLineTraceScene {
public:
  Scenario3Scene11(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController,
          int velocity = 50, bool rightEdge = true, const PIDParameters &pidParameters = {0.6, 0.01, 1.0}, int target = 54,
          int thresholdDistance = 0,
          int bottleDistace = 200) :
    FindBottleWithLineTraceScene(driveController, colorSensorController, ultrasonicSensorController, velocity, rightEdge, pidParameters, target, thresholdDistance, bottleDistace) {}
};
class Scenario3Scene12 : public StraightScene {
public:
  Scenario3Scene12(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 10) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene13 : public RotationScene {
public:
  Scenario3Scene13(DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -95) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene14 : public StraightScene {
public:
  Scenario3Scene14(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 80,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 85) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene15 : public StraightScene {
public:
  Scenario3Scene15(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = -35,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = -10) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene16 : public RotationScene {
public:
  Scenario3Scene16(DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -90) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene17 : public StraightScene {
public:
  Scenario3Scene17(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 30) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene18 : public RotationScene {
public:
  Scenario3Scene18(DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 90) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene19 : public StraightScene {
public:
  Scenario3Scene19(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 30) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene20 : public RotationScene {
public:
  Scenario3Scene20(DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 80) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene21 : public LineTraceScene {
public:
  Scenario3Scene21(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, bool rightEdge = false, const PIDParameters &pidParameters = {0.6, 0.005, 1.5}, int target = 54,
          LineColor color = LineColor::LINE_COLOR_BLUE,
          int thresholdDistance = 0) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};
class Scenario3Scene22 : public LineTraceScene {
public:
  Scenario3Scene22(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, bool rightEdge = false, const PIDParameters &pidParameters = {0.6, 0.005, 1.0}, int target = 62,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 15) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};
class Scenario3Scene23 : public LineTraceScene {
public:
  Scenario3Scene23(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50*0, bool rightEdge = false, const PIDParameters &pidParameters = {0.5*0, 0.005*0, 1.0*0}, int target = 54,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 100) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};

class Scenario3 : public Scenario {
public:
  Scenario3(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController);

  int process_scene() override;

  int switch_scene(int scene_index);

};

#endif // SCENARIO3_H