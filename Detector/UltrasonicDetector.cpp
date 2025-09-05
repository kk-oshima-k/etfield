#include "UltrasonicDetector.h"
#include <cstdio>

UltrasonicDetector::UltrasonicDetector(const UltrasonicSensorController &ultrasonicSensorController, int thresholdDistance) :
  Detector(),
  ultrasonicSensorController(ultrasonicSensorController),
  thresholdDistance(thresholdDistance) {
}

bool UltrasonicDetector::detect() {
  int distance = ultrasonicSensorController.get_distance();
  printf("%d\n", distance);
  if (distance < 0){
    return false;
  } else if (thresholdDistance > 0){
    return thresholdDistance > distance ; // Return true if detected within threshold, else false
  } else if(thresholdDistance < 0){
    return -thresholdDistance < distance; // Return true if detected within threshold, else false
  } else {
    return true; // thresholdDistance == 0 has no restrictions
  }
}

