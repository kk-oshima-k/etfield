#include "UltrasonicSensorController.h"

UltrasonicSensorController::UltrasonicSensorController() :
  UltrasonicSensor(EPort::PORT_F) {
}

int32_t UltrasonicSensorController::get_distance() const { 
  return UltrasonicSensor::getDistance();
}
