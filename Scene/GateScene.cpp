#include "GateScene.h"
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

extern int Gate;
extern int Gate_finish;
extern int camera_find;

GateScene::GateScene(DriveController &driveController,
                               int velocity) :
    straightDriver(driveController, velocity),
    find_count(0), time_count(0){
    init(&straightDriver);
}

void GateScene::enter_scene() {
    camera_find = 0;
} 

int GateScene::process_scene(){
    process_drive();
    if (camera_find == 1) {
        find_count += 1;
        camera_find = 0;
    }

    time_count += 1;
    printf("t:%d\n", time_count);

    if(time_count >= 100){

        printf("find_count:%d\n", find_count);

        if(find_count > 5){
            return 1;
        }else{
            return 2;
        }
    }

    return 0;
}