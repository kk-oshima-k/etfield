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
          int velocity = 50, bool rightEdge = true, const PIDParameters &pidParameters = {0.6, 0.01, 1.0}, int target = 51,
          int thresholdDistance = 0,
          int bottleDistace = 200) :
    FindBottleWithLineTraceScene(driveController, colorSensorController, ultrasonicSensorController, velocity, rightEdge, pidParameters, target, thresholdDistance, bottleDistace) {}
};
class Scenario3Scene2 : public StraightScene {
public:
  Scenario3Scene2(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, const PIDParameters &pidParameters = {0.6, 0.0, 0.0},
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 13) :
    StraightScene(angleController, driveController, colorSensorController, velocity, pidParameters, color, thresholdDistance) {}
};
class Scenario3Scene3 : public RotationScene {
public:
  Scenario3Scene3(AngleController &angleController, DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 90) :
    RotationScene(angleController, driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene4 : public StraightScene {
public:
  Scenario3Scene4(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 80, const PIDParameters &pidParameters = {0.6, 0.0, 0.0},
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 145) :
    StraightScene(angleController, driveController, colorSensorController, velocity, pidParameters, color, thresholdDistance) {}
};
class Scenario3Scene5 : public StraightScene {
public:
  Scenario3Scene5(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = -35, const PIDParameters &pidParameters = {0.6, 0.0, 0.0},
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = -18) :
    StraightScene(angleController, driveController, colorSensorController, velocity, pidParameters, color, thresholdDistance) {}
};
class Scenario3Scene6 : public RotationScene {
public:
  Scenario3Scene6(AngleController &angleController, DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -50) :
    RotationScene(angleController, driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene7 : public StraightScene {
public:
  Scenario3Scene7(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, const PIDParameters &pidParameters = {0.6, 0.0, 0.0},
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 60) :
    StraightScene(angleController, driveController, colorSensorController, velocity, pidParameters, color, thresholdDistance) {}
};
class Scenario3Scene8 : public RotationScene {
public:
  Scenario3Scene8(AngleController &angleController, DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -70) :
    RotationScene(angleController, driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene9 : public StraightScene {
public:
  Scenario3Scene9(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, const PIDParameters &pidParameters = {0.6, 0.0, 0.0},
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 0) :
    StraightScene(angleController, driveController, colorSensorController, velocity, pidParameters, color, thresholdDistance) {}
};
class Scenario3Scene10 : public RotationScene {
public:
  Scenario3Scene10(AngleController &angleController, DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 30) :
    RotationScene(angleController, driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene11 : public FindBottleWithLineTraceScene {
public:
  Scenario3Scene11(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController,
          int velocity = 50, bool rightEdge = false, const PIDParameters &pidParameters = {0.6, 0.01, 1.0}, int target = 51,
          int thresholdDistance = 0,
          int bottleDistace = 200) :
    FindBottleWithLineTraceScene(driveController, colorSensorController, ultrasonicSensorController, velocity, rightEdge, pidParameters, target, thresholdDistance, bottleDistace) {}
};
class Scenario3Scene12 : public StraightScene {
public:
  Scenario3Scene12(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, const PIDParameters &pidParameters = {0.6, 0.0, 0.0},
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 10) :
    StraightScene(angleController, driveController, colorSensorController, velocity, pidParameters, color, thresholdDistance) {}
};
class Scenario3Scene13 : public RotationScene {
public:
  Scenario3Scene13(AngleController &angleController, DriveController &driveController, int angularVelocity = -65, int thresholdAngle = -90) :
    RotationScene(angleController, driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene14 : public StraightScene {
public:
  Scenario3Scene14(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 80, const PIDParameters &pidParameters = {0.6, 0.0, 0.0},
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 87) :
    StraightScene(angleController, driveController, colorSensorController, velocity, pidParameters, color, thresholdDistance) {}
};
class Scenario3Scene15 : public StraightScene {
public:
  Scenario3Scene15(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = -30, const PIDParameters &pidParameters = {0.6, 0.0, 0.0},
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = -10) :
    StraightScene(angleController, driveController, colorSensorController, velocity, pidParameters, color, thresholdDistance) {}
};
class Scenario3Scene16 : public RotationScene {
public:
  Scenario3Scene16(AngleController &angleController, DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -90) :
    RotationScene(angleController, driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene17 : public StraightScene {
public:
  Scenario3Scene17(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, const PIDParameters &pidParameters = {0.6, 0.0, 0.0},
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 8) :
    StraightScene(angleController, driveController, colorSensorController, velocity, pidParameters, color, thresholdDistance) {}
};
class Scenario3Scene18 : public RotationScene {
public:
  Scenario3Scene18(AngleController &angleController, DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 70) :
    RotationScene(angleController, driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene19 : public StraightScene {
public:
  Scenario3Scene19(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, const PIDParameters &pidParameters = {0.6, 0.0, 0.0},
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 30) :
    StraightScene(angleController, driveController, colorSensorController, velocity, pidParameters, color, thresholdDistance) {}
};
class Scenario3Scene20 : public RotationScene {
public:
  Scenario3Scene20(AngleController &angleController, DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 100) :
    RotationScene(angleController, driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene21 : public LineTraceScene {
public:
  Scenario3Scene21(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, bool rightEdge = false, const PIDParameters &pidParameters = {0.6, 0.005, 1.5}, int target = 51,
          LineColor color = LineColor::LINE_COLOR_BLUE,
          int thresholdDistance = 0) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};
class Scenario3Scene22 : public LineTraceScene {
public:
  Scenario3Scene22(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, bool rightEdge = false, const PIDParameters &pidParameters = {0.6, 0.005, 1.0}, int target = 69,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 5) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};
class Scenario3Scene23 : public LineTraceScene {
public:
  Scenario3Scene23(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50*0, bool rightEdge = false, const PIDParameters &pidParameters = {0.5*0, 0.005*0, 1.0*0}, int target = 56,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 100) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};

class Scenario3 : public Scenario {
public:
  Scenario3(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController);

  int process_scene() override;

  int switch_scene(int scene_index);

};

#endif // SCENARIO3_H