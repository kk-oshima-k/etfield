#include "Scenario1.h"
#include <cstdio>

#ifdef MAKE_RASPIKE // not sim
extern FILE *fp;
#endif

Scenario1::Scenario1(AngleController &angleController, DriveController &driveController, const ColorSensorController &colorSensorController, const UltrasonicSensorController &ultrasonicSensorController) :
    Scenario(angleController, driveController, colorSensorController, ultrasonicSensorController)
{
    // scenes.push_back(new StraightScene(driveController, colorSensorController, 60, LineColor::LINE_COLOR_NONE, 0));
    scenes.push_back(new RotationScene(angleController, driveController, 65, 82));
    scenes.push_back(new RotationScene(angleController, driveController, 0, 90000000));
    // scenes.push_back(new StraightScene(driveController, colorSensorController, 0, LineColor::LINE_COLOR_NONE, 0));
    // scenes.push_back(new LineTraceScene(driveController, colorSensorController, 100, true, {0.6, 0.015, 1.5}, 56, LINE_COLOR_ANY, 174));
    // scenes.push_back(new LineTraceScene(driveController, colorSensorController, 60, true, {0.7, 0.01, 1.0}, 56, LINE_COLOR_ANY, 42));
    // scenes.push_back(new LineTraceScene(driveController, colorSensorController, 100, true, {0.6, 0.015, 1.5}, 56, LINE_COLOR_ANY, 50));
    // scenes.push_back(new LineTraceScene(driveController, colorSensorController, 0, true, {0, 0, 0}, 54, LINE_COLOR_NONE, 10));
    scenes.push_back(new Scenario1Scene1(driveController, colorSensorController));
    scenes.push_back(new Scenario1Scene2(driveController, colorSensorController, ultrasonicSensorController));
    scenes.push_back(new Scenario1Scene3(driveController,colorSensorController));
    scenes.push_back(new Scenario1Scene4(angleController, driveController));
    scenes.push_back(new Scenario1Scene5(driveController, colorSensorController));
    scenes.push_back(new Scenario1Scene6(angleController, driveController));
    scenes.push_back(new Scenario1Scene7(driveController, colorSensorController));
    scenes.push_back(new Scenario1Scene8(angleController, driveController));
    scenes.push_back(new Scenario1Scene9(driveController, colorSensorController));
    scenes.push_back(new Scenario1Scene10(driveController, colorSensorController));
    scenes.push_back(new Scenario1Scene11(driveController, colorSensorController));
    scenes.push_back(new Scenario1Scene12(driveController, colorSensorController));
    scenes.push_back(new Scenario1Scene13(driveController, colorSensorController));
}

int Scenario1::Scenario1::process_scene() {
    int scene_result = scenes[current_scene_index]->process_scene();
    if(scene_result == 0){
        return current_scene_index; // Stay in the current scene
    } else if (scene_result == 1 && current_scene_index < (int)scenes.size() - 1) {
        return current_scene_index + 1; // Move to the next scene
    }
    return -1;
}

int Scenario1::switch_scene(int scene_index){
    if (current_scene_index != scene_index){
        printf("Switch to Scenario 1 / Scene %d\n", scene_index);
#ifdef MAKE_RASPIKE // not sim
        fprintf(fp, "Switch to Scenario 1 / Scene %d\n", scene_index);
#endif
    }
    return Scenario::switch_scene(scene_index);
}
