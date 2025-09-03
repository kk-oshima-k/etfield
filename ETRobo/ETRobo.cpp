#include "ETRobo.h"
#include <cstdio>

ETRobo::ETRobo(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController) :
  current_scenario_index(0)
{
    scenarios.push_back(new Scenario1(driveController, colorSensorController, ultrasonicSensorController));
}

ETRobo::~ETRobo() {
  terminate();
  while(!scenarios.empty()) {
    delete scenarios.back(); // Clean up the allocated scenarios
    scenarios.pop_back();
  }
}

void ETRobo::initialize(){
  scenarios[current_scenario_index]->enter_scenario();
}

int ETRobo::process() {
  int next_scenario_index = process_scenario(); // Process the current scenario
  if(switch_scenario(next_scenario_index) == -1) // Switch to the next scenario based on the result
    return -1;
  return 0;
}

void ETRobo::terminate() {
  terminate_scenario(); // Terminate current scenario
  current_scenario_index = -1; // Reset the scenario index
}

int ETRobo::process_scenario() {
  int scenario_result = scenarios[current_scenario_index]->process_scenario();
  if (scenario_result == 0){
    return current_scenario_index;
  }else if (scenario_result == 1 && current_scenario_index < scenarios.size() - 1) {
    return current_scenario_index + 1; // Move to the next scenario
  }
  return -1;
}

int ETRobo::switch_scenario(int scenario_index) {
  int previous_scenario_index = current_scenario_index;
  if (scenario_index < 0 || scenario_index >= scenarios.size()) {
    current_scenario_index = -1; // End the scenario if the scene index is invalid
    return -1; // Invalid scene index
  }
  if(current_scenario_index != scenario_index){
    int previous_scenario_index = current_scenario_index;
    current_scenario_index = scenario_index;
    scenarios[current_scenario_index]->enter_scenario();
    return previous_scenario_index; // Return the previous scenario index
  }
  return current_scenario_index;
}

void ETRobo::terminate_scenario() {
  scenarios[current_scenario_index]->terminate_scenario(); // Terminate the current scenario
}