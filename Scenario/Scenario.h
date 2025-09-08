#ifndef SCENARIO_H
#define SCENARIO_H

#include <vector>
#include "../Device/DriveController.h"
#include "../Device/ColorSensorController.h"
#include "../Device/UltrasonicSensorController.h"
#include "../Scene/Scene.h"

class Scenario {
public:
  Scenario(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController);
  virtual ~Scenario();

public:
  void enter_scenario();
  int process_scenario();
  void terminate_scenario();

protected:
  virtual int process_scene() = 0;
  virtual int switch_scene(int scene_index);
  void terminate_scene();

protected:
  int current_scene_index;
  std::vector<Scene *> scenes;
};

#endif // SCENARIO_H