#ifndef COLOR_DETECTOR_H
#define COLOR_DETECTOR_H

#include "Detector.h"
#include "../Common/Common.h"
#include "../Device/ColorSensorController.h"

using namespace spikeapi;

class ColorDetector : public Detector {
public:
  ColorDetector(const ColorSensorController &colorSensorController, LineColor color=LineColor::LINE_COLOR_BLACK);

  bool detect() override;

private:
  bool checkColor(const ColorSensor::HSV& hsv, const LineColorThresholds& thresholds);

private:
  static const LineColorThresholds BLACK_THRESHOLD;
  static const LineColorThresholds RED_THRESHOLD;
  static const LineColorThresholds BLUE_THRESHOLD;
  static const LineColorThresholds GRAY_THRESHOLD;

private:
  const ColorSensorController &colorSensorController;

  LineColor color;
};

#endif // COLOR_DETECTOR_H