#ifndef COLOR_SENSOR_CONTROLLER_H
#define COLOR_SENSOR_CONTROLLER_H

#include <ColorSensor.h>

using namespace spikeapi;

class ColorSensorController : public ColorSensor {
public:
  ColorSensorController();
};

#endif // COLOR_SENSOR_CONTROLLER_H