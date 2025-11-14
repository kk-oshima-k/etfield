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

  typedef struct Dev{
    float d;
  };

  AngleController();

  myxyz getAngle();

  void resetAngle();

private:
  myxyz xyz; 
  Dev dev;

  float vprev = 0.0;
  float aprev = 0.0;
  // テスト用
  // float ano_z;
  // float zdiffmax;
};

#endif // ANGLE_CONTROLLER_H