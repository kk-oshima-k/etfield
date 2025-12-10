#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "../Driver/Driver.h"
#include "../Detector/Detector.h"

class Scene {
protected:
  Scene();
  void init(Driver *driver, std::vector<Detector *> detectors=std::vector<Detector *>());

public:
  virtual ~Scene();

public:
  virtual void enter_scene();
  virtual int process_scene();
  virtual void terminate_scene();

protected:
  virtual void process_drive();
  virtual bool process_finish_detect();
  virtual void terminate_drive();

  Driver *driver;
  std::vector<Detector *> detectors;
};

#endif // SCENE_H