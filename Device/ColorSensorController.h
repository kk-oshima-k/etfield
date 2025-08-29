#ifndef COLOR_SENSOR_CONTROLLER_H
#define COLOR_SENSOR_CONTROLLER_H

#include <ColorSensor.h>

using namespace spikeapi;

class ColorSensorController : public ColorSensor {
public:

  typedef struct myHSV_{
    uint16_t h;
    uint16_t s;
    uint16_t v;
  } myHSV;
  
  ColorSensorController();
  void getHSV(HSV& hsv, bool surface = true ) const;
  void getHSV_test(myHSV& hsv) const;
  
};

#endif // COLOR_SENSOR_CONTROLLER_H