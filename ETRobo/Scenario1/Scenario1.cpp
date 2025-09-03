#include "Scenario1.h"
#include <cstdio>

extern FILE *fp;

Scenario1::Scenario1(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController) :
    Scenario(driveController, colorSensorController, ultrasonicSensorController)
{
    scenes.push_back(new Scenario1Scene1(driveController, colorSensorController, ultrasonicSensorController));
    scenes.push_back(new Scenario1Scene2(driveController));
    scenes.push_back(new Scenario1Scene3(driveController, colorSensorController));
    scenes.push_back(new Scenario1Scene4(driveController));
    scenes.push_back(new Scenario1Scene5(driveController, colorSensorController));
    scenes.push_back(new Scenario1Scene6(driveController));
    scenes.push_back(new Scenario1Scene7(driveController, colorSensorController));
}

int Scenario1::Scenario1::process_scene() {
    int scene_result = scenes[current_scene_index]->process_scene();
    if(scene_result == 0){
        return current_scene_index; // Stay in the current scene
    } else if (scene_result == 1 && current_scene_index < scenes.size() - 1) {
        return current_scene_index + 1; // Move to the next scene
    }
    return -1;
}

int Scenario1::switch_scene(int scene_index){
    if (current_scene_index != scene_index){
        printf("Switch to Scenario 1 / Scene %d\n", scene_index);
        fprintf(fp, "Switch to Scenario 1 / Scene %d\n", scene_index);
    }
    return Scenario::switch_scene(scene_index);
}
