#include "ColorDetector.h"

const LineColorThresholds ColorDetector::WHITE_THRESHOLD={
  {359,  20, 100},   // upperThreshold
  {  0,   0,  80}    // lowerThreshold
};
const LineColorThresholds ColorDetector::BLACK_THRESHOLD={
  {359,  40,  54},   // upperThreshold
  {  0,   0,   0}    // lowerThreshold
};
const LineColorThresholds ColorDetector::RED_THRESHOLD={
  { 30, 255, 255},   // upperThreshold
  {330, 200, 200}    // lowerThreshold
};
const LineColorThresholds ColorDetector::BLUE_THRESHOLD={
  {235, 120, 60},   // upperThreshold
  {190, 50, 30}    // lowerThreshold
};
const LineColorThresholds ColorDetector::GRAY_THRESHOLD={
  {359,  80,  80},   // upperThreshold
  {  0,   0,   0}    // lowerThreshold
};

ColorDetector::ColorDetector(const ColorSensorController &colorSensorController, LineColor color) :
  Detector(),
  colorSensorController(colorSensorController),
  color(color) {
}

bool ColorDetector::detect() {
  if(color == LINE_COLOR_NONE){
    return false;
  } else if (color == LINE_COLOR_ANY){
    return true;
  }
  
  ColorSensorController::myHSV hsv;
  colorSensorController.getHSV(hsv);

  if (color == LINE_COLOR_WHITE) {
    return checkColor(hsv, WHITE_THRESHOLD);
  } else if(color == LINE_COLOR_BLACK) {
    return checkColor(hsv, BLACK_THRESHOLD);
  } else if (color == LINE_COLOR_RED) {
    return checkColor(hsv, RED_THRESHOLD);
  } else if (color == LINE_COLOR_BLUE) {
    return checkColor(hsv, BLUE_THRESHOLD);
  } else if (color == LINE_COLOR_GRAY) {
    return checkColor(hsv, GRAY_THRESHOLD);
  } else {
    // LINE_COLOR_NONE or any other color not defined
    return false; // Not detected
  }
}

bool ColorDetector::checkColor(const ColorSensorController::myHSV& hsv, const LineColorThresholds& thresholds) {
  if (thresholds.lowerThreshold.h < thresholds.upperThreshold.h) {
    // Normal case where lower threshold is less than upper threshold
    return (thresholds.lowerThreshold.h <= hsv.h && hsv.h <= thresholds.upperThreshold.h &&
            thresholds.lowerThreshold.s <= hsv.s && hsv.s <= thresholds.upperThreshold.s &&
            thresholds.lowerThreshold.v <= hsv.v && hsv.v <= thresholds.upperThreshold.v);
  } else {
    // Special case where lower threshold is greater than upper threshold (wrap-around case)
    return ((thresholds.lowerThreshold.h <= hsv.h || hsv.h <= thresholds.upperThreshold.h) &&
            thresholds.lowerThreshold.s <= hsv.s && hsv.s <= thresholds.upperThreshold.s &&
            thresholds.lowerThreshold.v <= hsv.v && hsv.v <= thresholds.upperThreshold.v);
  }
}
