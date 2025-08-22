#include "Scenario2.h"
#include <cstdio>

Scenario2::Scenario2(DriveController &driveController, const ColorSensorController &colorSensorController) :
    Scenario(driveController, colorSensorController)
{
    scenes.push_back(new Scenario2Scene1(driveController, colorSensorController));
    scenes.push_back(new Scenario2Scene2(driveController));
    scenes.push_back(new Scenario2Scene3(driveController, colorSensorController));
//    scenes.push_back(new Scenario2Scene4(driveController));
//    scenes.push_back(new Scenario2Scene5(driveController, colorSensorController));
//    scenes.push_back(new Scenario2Scene6(driveController));
//    scenes.push_back(new Scenario2Scene7(driveController, colorSensorController));
//    scenes.push_back(new Scenario2Scene8(driveController));
//    scenes.push_back(new Scenario2Scene9(driveController, colorSensorController));
//    scenes.push_back(new Scenario2Scene10(driveController));
//    scenes.push_back(new Scenario2Scene11(driveController, colorSensorController));
//    scenes.push_back(new Scenario2Scene12(driveController));
//    scenes.push_back(new Scenario2Scene13(driveController, colorSensorController));
//    scenes.push_back(new Scenario2Scene14(driveController));
//    scenes.push_back(new Scenario2Scene15(driveController, colorSensorController));
//    scenes.push_back(new Scenario2Scene16(driveController));
//    scenes.push_back(new Scenario2Scene17(driveController, colorSensorController));
}

int Scenario2::Scenario2::process_scene() {
    int scene_result = scenes[current_scene_index]->process_scene();
    if(scene_result == 0){
        return current_scene_index; // Stay in the current scene
    } else if (scene_result == 1 && current_scene_index < scenes.size() - 1) {
        return current_scene_index + 1; // Move to the next scene
    }
    return -1;
}

int Scenario2::switch_scene(int scene_index){
    if (this->current_scene_index != scene_index)
        printf("Switch to Scenario 2 / Scene %d\n", scene_index);
    Scenario::switch_scene(scene_index);
}