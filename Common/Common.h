#ifndef COMMON_H
#define COMMON_H

#include "../Device/ColorSensorController.h"

enum LineColor {
  LINE_COLOR_NONE = 0,
  LINE_COLOR_WHITE = 1,
  LINE_COLOR_BLACK = 2,
  LINE_COLOR_RED = 3,
  LINE_COLOR_BLUE = 4,
  LINE_COLOR_GRAY = 5,
//   LINE_COLOR_GREEN = 6,
//   LINE_COLOR_YELLOW = 7,
};

struct LineColorThresholds {
  ColorSensorController::HSV upperThreshold;
  ColorSensorController::HSV lowerThreshold;
};

struct PIDParameters {
  double kp;
  double ki;
  double kd;
};

#endif // COMMON_H