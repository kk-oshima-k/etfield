#ifndef GATE_SCENE_H
#define GATE_SCENE_H

#include "Scene.h"
#include "../Common/Common.h"
#include "../Device/DriveController.h"
#include "../Device/ColorSensorController.h"
#include "../Driver/StraightDriver.h"
#include "../Detector/DistanceDetector.h"

using namespace spikeapi;


class GateScene : public Scene {
public:
  GateScene(DriveController &driveController,
             int velocity = 0);

  void enter_scene() override;
  int process_scene();

protected:
  StraightDriver straightDriver;
  int find_count;
  int time_count;
};

#endif // GATE_SCENE_H