#ifndef ETROBO_H
#define ETROBO_H

#include "../Device/DriveController.h"
#include "../Device/ColorSensorController.h"
#include "Scenario2/Scenario2.h"

class ETRobo {
public:
  ETRobo(DriveController &driveController, const ColorSensorController &colorSensorController);
  ~ETRobo();

  void initialize();
  int process();
  void terminate();

private:
  int process_scenario();
  int switch_scenario(int scenario_index);
  void terminate_scenario();

private:
  int current_scenario_index;
  std::vector<Scenario *> scenarios;
};

#endif // ETROBO_H