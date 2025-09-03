#ifndef LINE_TRACER_H
#define LINE_TRACER_H

#include "Driver.h"
#include "../Common/Common.h"
#include "../Device/DriveController.h"
#include "../Device/ColorSensorController.h"

using namespace spikeapi;

class LineTracer : public Driver {
public:
  LineTracer(DriveController &driveController, const ColorSensorController &colorSensorController, int velocity, bool rightEdges, const PIDParameters &pidParameters, int target=127);

  void drive() override;

private:
  int calculate_PID_gain();

private:
  const ColorSensorController &colorSensorController;

  int velocity;
  bool rightEdge; // true: Right, false: Left
  PIDParameters pidParameters;
  
  // PID制御用の変数
  int target; // 目標値
  int previousError;
  double integral;

#ifndef MAKE_RASPIKE
  bool simup;
#endif
};

#endif // LINE_TRACER_H