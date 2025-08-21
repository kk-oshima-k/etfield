#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "../Driver/Driver.h"
#include "../Detector/Detector.h"

class Scene {
protected:
  Scene();
  void init(Driver *driver, std::vector<Detector *> detectors);

public:
  virtual ~Scene();

public:
  int process_scene();
  void terminate_scene();

protected:
  void process_drive();
  bool process_finish_detect();
  void terminate_drive();

  Driver *driver;
  std::vector<Detector *> detectors;
};

#endif // SCENE_H