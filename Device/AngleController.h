#ifndef ANGLE_CONTROLLER_H
#define ANGLE_CONTROLLER_H

#include <IMU.h>
#include <math.h>

using namespace spikeapi;

class AngleController : public IMU {
public:

  typedef struct myxyz{
    float x;
    float y;
    float z;
  };

  AngleController();

  myxyz getAngle();

  void resetAngle();

private:
  myxyz xyz; 
};

#endif // ANGLE_CONTROLLER_H