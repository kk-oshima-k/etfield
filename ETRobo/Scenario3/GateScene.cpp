#include "GateScene.h"
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>

extern int Gate;

GateScene::GateScene(DriveController &driveController, const ColorSensorController &colorSensorController,
                               int velocity,
                               LineColor color,
                               int thresholdDistance) :
  straightDriver(driveController, velocity),
  colorDetector(colorSensorController, color),
  distanceDetector(driveController, thresholdDistance){
  init(&straightDriver, {&colorDetector, &distanceDetector});

}

void LineTraceScene::enter_scene() {
  distanceDetector.reset_distance();
} 

void GateScene::process_scene(){
    int count = 0;
    int Gate = 0;

    auto start = std::chrono::steady_clock::now();

    while (true) {
        if (camera_find == 1) {
            count++;
        }

        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - start);

        if (elapsed.count() >= 5000) {
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    if (count >= 10) {
        Gate = 1;
    }

    std::cout << count << std::endl;
    std::cout << Gate << std::endl;

    return 0;

}