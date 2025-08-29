#ifndef ULTRASONIC_SENSOR_CONTROLLER_H
#define ULTRASONIC_SENSOR_CONTROLLER_H

#include <UltrasonicSensor.h>

using namespace spikeapi;

class UltrasonicSensorController : public UltrasonicSensor {
public:

  UltrasonicSensorController();
  int32_t getDistance() const;
  
};

#endif // ULTRASONIC_SENSOR_CONTROLLER_H