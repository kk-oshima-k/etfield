#ifndef SCENARIO2_H
#define SCENARIO2_H

#include "../../Scenario/Scenario.h"
#include "../../Scene/LineTraceScene.h"
#include "../../Scene/StraightScene.h"
#include "../../Scene/RotationScene.h"

class Scenario2Scene1 : public LineTraceScene {
public:
  Scenario2Scene1(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, bool rightEdge = true, const PIDParameters &pidParameters = {0.6, 0.005, 1.0}, int target = 69,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 0) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};
class Scenario2Scene2 : public RotationScene {
public:
  Scenario2Scene2(DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 10) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario2Scene3 : public StraightScene {
public:
  Scenario2Scene3(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 20) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario2Scene4 : public RotationScene {
public:
  Scenario2Scene4(DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 25) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario2Scene5 : public LineTraceScene {
public:
  Scenario2Scene5(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, bool rightEdge = false, const PIDParameters &pidParameters = {0.6, 0.005, 1.0}, int target = 51,
          LineColor color = LineColor::LINE_COLOR_BLUE,
          int thresholdDistance = 60) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};
class Scenario2Scene6 : public RotationScene {
public:
  Scenario2Scene6(DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 3) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario2Scene7 : public StraightScene {
public:
  Scenario2Scene7(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 35) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario2Scene8 : public RotationScene {
public:
  Scenario2Scene8(DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -20) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario2Scene9 : public LineTraceScene {
public:
  Scenario2Scene9(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, bool rightEdge = true, const PIDParameters &pidParameters = {0.7, 0.005, 1.0}, int target = 51,
          LineColor color = LineColor::LINE_COLOR_BLUE,
          int thresholdDistance = 100) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};
class Scenario2Scene10 : public RotationScene {
public:
  Scenario2Scene10(DriveController &driveController, int angularVelocity = -60, int thresholdAngle = -15) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario2Scene11 : public StraightScene {
public:
  Scenario2Scene11(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 35) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario2Scene12 : public RotationScene {
public:
  Scenario2Scene12(DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 10) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario2Scene13 : public LineTraceScene {
public:
  Scenario2Scene13(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, bool rightEdge = false, const PIDParameters &pidParameters = {0.6, 0.005, 1.0}, int target = 51,
          LineColor color = LineColor::LINE_COLOR_BLUE,
          int thresholdDistance = 20) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};
class Scenario2Scene14 : public RotationScene {
public:
  Scenario2Scene14(DriveController &driveController, int angularVelocity = 40, int thresholdAngle = 5) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario2Scene15 : public StraightScene {
public:
  Scenario2Scene15(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50,
          LineColor color = LineColor::LINE_COLOR_WHITE,
          int thresholdDistance = 20) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario2Scene16 : public RotationScene {
public:
  Scenario2Scene16(DriveController &driveController, int angularVelocity = 60, int thresholdAngle = 10) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario2Scene17 : public LineTraceScene {
public:
  Scenario2Scene17(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 50, bool rightEdge = true, const PIDParameters &pidParameters = {0.6, 0.005, 1.0}, int target = 51,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 25) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};

class Scenario2 : public Scenario {
public:
  Scenario2(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController);

  int process_scene() override;

  int switch_scene(int scene_index);

};

#endif // SCENARIO2_H