#include "Scenario3.h"
#include <cstdio>

#ifdef MAKE_RASPIKE // not sim
extern FILE *fp;
#endif

Scenario3::Scenario3(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController) :
    Scenario(driveController, colorSensorController, ultrasonicSensorController)
{
    scenes.push_back(new Scenario3Scene1(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene2(driveController));
    scenes.push_back(new Scenario3Scene3(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene4(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene5(driveController));
    scenes.push_back(new Scenario3Scene6(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene7(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene8(driveController));
    scenes.push_back(new Scenario3Scene9(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene10(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene11(driveController));
    scenes.push_back(new Scenario3Scene12(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene13(driveController));
    scenes.push_back(new Scenario3Scene14(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene15(driveController));
    scenes.push_back(new Scenario3Scene16(driveController, colorSensorController));
}

int Scenario3::Scenario3::process_scene() {
    printf("%d\n", current_scene_index);
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
#ifdef MAKE_RASPIKE // not sim
        fprintf(fp, "Switch to Scenario 3 / Scene %d\n", scene_index);
#endif
    }
    return Scenario::switch_scene(scene_index);
}
