#include "Scenario3.h"
#include <cstdio>

#ifdef MAKE_RASPIKE // not sim
extern FILE *fp;
#endif


Scenario3::Scenario3(DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController) :
    Scenario(driveController, colorSensorController, ultrasonicSensorController)
{
    scenes.push_back(new Scenario3Scene0(driveController, colorSensorController, ultrasonicSensorController));
    scenes.push_back(new Scenario3Scene1(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene2(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene3(driveController));
    scenes.push_back(new Scenario3Scene4(driveController));
    scenes.push_back(new Scenario3Scene5(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene6(driveController));
    scenes.push_back(new Scenario3Scene7(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene8(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene9(driveController));
    scenes.push_back(new Scenario3Scene10(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene11(driveController));
    scenes.push_back(new Scenario3Scene12(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene13(driveController));
    scenes.push_back(new Scenario3Scene14(driveController, colorSensorController, ultrasonicSensorController));
    scenes.push_back(new Scenario3Scene15(driveController, colorSensorController)); 
    scenes.push_back(new Scenario3Scene16(driveController));
    scenes.push_back(new Scenario3Scene17(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene18(driveController));
    scenes.push_back(new Scenario3Scene19(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene20(driveController));
    scenes.push_back(new Scenario3Scene21(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene22(driveController));
    scenes.push_back(new Scenario3Scene23(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene24(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene25(driveController));
    scenes.push_back(new Scenario3Scene26(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene27(driveController));
    scenes.push_back(new Scenario3Scene28(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene29(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene30(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene31(driveController));
    scenes.push_back(new Scenario3Scene32(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene33(driveController));
    scenes.push_back(new Scenario3Scene34(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene35(driveController));
    scenes.push_back(new Scenario3Scene36(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene37(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene38(driveController));
    scenes.push_back(new Scenario3Scene39(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene40(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene41(driveController, colorSensorController));
}

int Scenario3::Scenario3::process_scene() {
    printf("%d\n", current_scene_index);
    int scene_result = scenes[current_scene_index]->process_scene();
    printf("res:%d\n", scene_result);
    if(scene_result == 0){
        return current_scene_index; // Stay in the current scene
    } else if (current_scene_index == 4){
        if(scene_result == 1){
            return 5;
        }else if(scene_result == 2){
            return 31;
        }
    } else if (current_scene_index == 18 && scene_result == 2){
        return 40;
    } else if (current_scene_index == 22 && scene_result == 2){
        return 41;
    } else if (current_scene_index == 39 && scene_result == 2){
        return 11;
    } else if (current_scene_index == 40 && scene_result == 2){
        return 20;
    } else if (current_scene_index == 41 && scene_result == 2){
        return 24;
    } else if (scene_result == 1 && current_scene_index < (int)scenes.size() - 1) {
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
