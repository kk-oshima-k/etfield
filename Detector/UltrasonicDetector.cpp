#include "UltrasonicDetector.h"
#include <cstdio>

UltrasonicDetector::UltrasonicDetector(const UltrasonicSensorController &ultrasonicSensorController, int bottleDistance) :
  Detector(),
  ultrasonicSensorController(ultrasonicSensorController),
  bottleDistance(bottleDistance) {
}

bool UltrasonicDetector::detect() {
  int distance = ultrasonicSensorController.get_distance();
  printf("%d\n", distance);
  if (distance < 0){
    return false;
  } else if (bottleDistance > 0){
    return bottleDistance > distance ; // Return true if detected within threshold, else false
  } else if(bottleDistance < 0){
    return -bottleDistance < distance; // Return true if detected within threshold, else false
  } else {
    return true; // bottleDistance == 0 has no restrictions
  }
}

