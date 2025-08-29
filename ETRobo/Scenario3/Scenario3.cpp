#include "Scenario3.h"
#include <cstdio>

extern FILE *fp;

Scenario3::Scenario3(DriveController &driveController, const ColorSensorController &colorSensorController) :
    Scenario(driveController, colorSensorController)
{
    scenes.push_back(new Scenario3Scene1(driveController, colorSensorController));
}

int Scenario3::Scenario3::process_scene() {
    int scene_result = scenes[current_scene_index]->process_scene();
    if(scene_result == 0){
        return current_scene_index; // Stay in the current scene
    } else if (scene_result == 1 && current_scene_index < scenes.size() - 1) {
        return current_scene_index + 1; // Move to the next scene
    }
    return -1;
}

int Scenario3::switch_scene(int scene_index){
    if (current_scene_index != scene_index){
        printf("Switch to Scenario 3 / Scene %d\n", scene_index);
        fprintf(fp, "Switch to Scenario 3 / Scene %d\n", scene_index);
    }
    return Scenario::switch_scene(scene_index);
}
