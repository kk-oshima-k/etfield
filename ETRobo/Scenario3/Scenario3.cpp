#include "Scenario3.h"
#include <cstdio>

#ifdef MAKE_RASPIKE // not sim
extern FILE *fp;
#endif


Scenario3::Scenario3(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController) :
    Scenario(angleController, driveController, colorSensorController, ultrasonicSensorController),
    gate(0)
{
    scenes.push_back(new Scenario3Scene0(driveController, colorSensorController, ultrasonicSensorController));
    scenes.push_back(new Scenario3Scene1(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene2(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene3(angleController, driveController));
    scenes.push_back(new Scenario3Scene4(angleController, driveController));
    scenes.push_back(new Scenario3Scene5(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene6(angleController, driveController));
    scenes.push_back(new Scenario3Scene7(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene8(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene9(angleController, driveController));
    scenes.push_back(new Scenario3Scene10(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene11(angleController, driveController));
    scenes.push_back(new Scenario3Scene12(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene13(angleController, driveController));
    scenes.push_back(new Scenario3Scene14(driveController, colorSensorController, ultrasonicSensorController));
    scenes.push_back(new Scenario3Scene15(angleController, driveController, colorSensorController)); 
    scenes.push_back(new Scenario3Scene16(angleController, driveController));
    scenes.push_back(new Scenario3Scene17(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene18(angleController, driveController));
    scenes.push_back(new Scenario3Scene19(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene20(angleController, driveController));
    scenes.push_back(new Scenario3Scene21(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene22(angleController, driveController));
    scenes.push_back(new Scenario3Scene23(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene24(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene25(angleController, driveController));
    scenes.push_back(new Scenario3Scene26(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene27(angleController, driveController));
    scenes.push_back(new Scenario3Scene28(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene29(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene30(driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene31(angleController, driveController));
    scenes.push_back(new Scenario3Scene32(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene33(angleController, driveController));
    scenes.push_back(new Scenario3Scene34(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene35(angleController, driveController));
    scenes.push_back(new Scenario3Scene36(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene37(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene38(angleController, driveController));
    scenes.push_back(new Scenario3Scene39(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene40(angleController, driveController, colorSensorController));
    scenes.push_back(new Scenario3Scene41(angleController, driveController, colorSensorController));
}

int Scenario3::Scenario3::process_scene() {
    printf("%d\n", current_scene_index);
    int scene_result = scenes[current_scene_index]->process_scene();
    printf("res:%d\n", scene_result);
    if(scene_result == 0){
        return current_scene_index; // Stay in the current scene
    } else if (current_scene_index == 4){
        if(scene_result == 1){
            gate = 1;
            return 5;
        }else if(scene_result == 2){
            gate = 2;
            return 31;
        }
    } else if (current_scene_index == 39){
        return 11;
    } else if (current_scene_index == 40){
        return 20;
    } else if (current_scene_index == 41){
        return 24;
    } else if (current_scene_index == 15){
        return 18;
    } else if (current_scene_index == 18){
        if (gate == 1)
            return 19;  
        else if (gate == 2)
            return 40;
    } else if (current_scene_index == 22){
        if (gate == 1)
            return 23;  
        else if (gate == 2)
            return 41;
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
