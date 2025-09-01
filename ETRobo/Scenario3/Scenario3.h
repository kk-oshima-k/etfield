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
  Scenario3Scene2(DriveController &driveController, int angularVelocity = -30, int thresholdAngle = -90) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene3 : public StraightScene {
public:
  Scenario3Scene3(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 100,
          LineColor color = LineColor::LINE_COLOR_BLUE,
          int thresholdDistance = 100) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene4 : public StraightScene {
public:
  Scenario3Scene4(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 100,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 100) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene5 : public RotationScene {
public:
  Scenario3Scene2(DriveController &driveController, int angularVelocity = -30, int thresholdAngle = -90) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene6 : public StraightScene {
public:
  Scenario3Scene6(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 100,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 100) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene7 : public LineTraceScene {
public:
  Scenario3Scene7(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 300, bool rightEdge = false, const PIDParameters &pidParameters = {0.25, 0.005*0, 0.25*0}, int target = 525,
          LineColor color = LineColor::LINE_COLOR_RED,
          int thresholdDistance = 100) :
    LineTraceScene(driveController, colorSensorController, velocity, rightEdge, pidParameters, target, color, thresholdDistance) {}
};
class Scenario3Scene8 : public RotationScene {
public:
  Scenario3Scene8(DriveController &driveController, int angularVelocity = 100, int thresholdAngle = 90) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene9 : public StraightScene {
public:
  Scenario3Scene9(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 100,
          LineColor color = LineColor::LINE_COLOR_BLUE,
          int thresholdDistance = 100) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene10 : public StraightScene {
public:
  Scenario3Scene10(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 100,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 100) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene11 : public RotationScene {
public:
  Scenario3Scene11(DriveController &driveController, int angularVelocity = 100, int thresholdAngle = -90) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene12 : public StraightScene {
public:
  Scenario3Scene12(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 100,
          LineColor color = LineColor::LINE_COLOR_ANY,
          int thresholdDistance = 100) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene13 : public RotationScene {
public:
  Scenario3Scene11(DriveController &driveController, int angularVelocity = 100, int thresholdAngle = 90) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};
class Scenario3Scene14 : public StraightScene {
public:
  Scenario3Scene14(DriveController &driveController, const ColorSensorController &colorSensorController,
          int velocity = 100,
          LineColor color = LineColor::LINE_COLOR_BLACK,
          int thresholdDistance = 100) :
    StraightScene(driveController, colorSensorController, velocity, color, thresholdDistance) {}
};
class Scenario3Scene15 : public RotationScene {
public:
  Scenario3Scene15(DriveController &driveController, int angularVelocity = 100, int thresholdAngle = 90) :
    RotationScene(driveController, angularVelocity, thresholdAngle) {}
};

class Scenario3 : public Scenario {
public:
  Scenario3(DriveController &driveController, const ColorSensorController &colorSensorController);

  int process_scene() override;

  int switch_scene(int scene_index);

};

#endif // SCENARIO3_H