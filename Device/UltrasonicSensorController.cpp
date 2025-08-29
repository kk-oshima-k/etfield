#include "UltrasonicSensorController.h"

UltrasonicSensorController::UltrasonicSensorController() :
  UltrasonicSensor(EPort::PORT_F) {
}

int32_t UltrasonicSensorController::getDistance() const { 
  return UltrasonicSensor::getDistance();
}
