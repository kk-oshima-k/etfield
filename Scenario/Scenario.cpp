#include "Scenario.h"
#include <cstdio>

#ifdef MAKE_RASPIKE // not sim
extern FILE *fp;
#endif

Scenario::Scenario(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController) :
  current_scene_index(0)
{
}

Scenario::~Scenario() {
  terminate_scenario();
  while(!scenes.empty()) {
    delete scenes.back(); // Clean up the allocated scenes
    scenes.pop_back();
  }
}

void Scenario::enter_scenario() {
  scenes[current_scene_index]->enter_scene();
}

int Scenario::process_scenario() {
  int next_scene_index = process_scene(); // Process the current scene
  if(switch_scene(next_scene_index) == -1){ // Switch to the next scene based on the result
    return 1;
  }
  return 0;
}

void Scenario::terminate_scenario() {
  terminate_scene(); // Terminate the current scene
  current_scene_index = -1; // Reset the scene index
}

int Scenario::switch_scene(int scene_index) {
  if (scene_index < 0 || scene_index >= (int)scenes.size()) {
    current_scene_index = -1; // End the scenario if the scene index is invalid
    return -1; // Invalid scene index
  }
  if(current_scene_index != scene_index){
    printf("Switch to Scene%d\n", scene_index);
#ifdef MAKE_RASPIKE // not sim
    fprintf(fp, "Switch to Scene%d\n", scene_index);
#endif
    int previous_scene_index = current_scene_index;
    current_scene_index = scene_index;
    scenes[current_scene_index]->enter_scene(); // Enter the new scene
    return previous_scene_index; // Return the previous scene index
  }
  return current_scene_index; // No change in scene, return current index
}

void Scenario::terminate_scene() {
  if (current_scene_index >= 0 && current_scene_index < (int)scenes.size()) {
    scenes[current_scene_index]->terminate_scene(); // Terminate the current scene
  }
}