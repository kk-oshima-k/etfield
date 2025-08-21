#include "Scene.h"

Scene::Scene(){
}

void Scene::init(Driver *driver, std::vector<Detector *> detectors) {
  this->driver = driver;
  this->detectors = detectors;
}

Scene::~Scene() {
  terminate_scene();
}

int Scene::process_scene() {
  process_drive();
  if(process_finish_detect()) {
    return 1; // Scene finished successfully
  }
  return 0;
}

void Scene::terminate_scene() {
  terminate_drive();  
}

void Scene::process_drive() {
  driver->drive();
}

bool Scene::process_finish_detect() {
  for (auto &detector : detectors) {
    if (detector->detect()) {
      return true;
    }
  }
  return false;
}

void Scene::terminate_drive() {
  driver->stop();
}
