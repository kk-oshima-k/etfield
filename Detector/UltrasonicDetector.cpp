#include "UltrasonicDetector.h"

UltrasonicDetector::UltrasonicDetector(const UltrasonicSensorController &ultrasonicSensorController, int thresholdDistance) :
  Detector(),
  ultrasonicSensorController(ultrasonicSensorController),
  thresholdDistance(thresholdDistance) {
}

bool UltrasonicDetector::detect() {
  int distance = ultrasonicSensorController.get_distance();
  if (thresholdDistance > 0){
    return thresholdDistance < distance ; // Return true if detected within threshold, else false
  } else if(thresholdDistance < 0){
    return distance < thresholdDistance ; // Return true if detected within threshold, else false
  } else {
    return true; // thresholdDistance == 0 has no restrictions
  }
}

