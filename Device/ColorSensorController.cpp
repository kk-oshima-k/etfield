#include "ColorSensorController.h"

ColorSensorController::ColorSensorController() :
  ColorSensor(EPort::PORT_E) {
}

void ColorSensorController::getHSV(HSV& hsv, bool surface) const { 
  ColorSensor::getHSV(hsv, surface);
  return;
}
void ColorSensorController::getHSV_test(myHSV& hsv) const { 
  RGB rgb;
  getRGB(rgb);
  uint16_t max,min;
  
  if(rgb.r > rgb.g){
    if(rgb.r > rgb.b){
      max = rgb.r;
      if(rgb.g > rgb.b){
        min = rgb.b;
        hsv.h = 60 * (rgb.g - rgb.b) / (max - min);
      }else{
        min = rgb.g;
        hsv.h = 60 * (rgb.g - rgb.b) / (max - min) + 360;
      }
      
    }else{
      max = rgb.b;
      min = rgb.g;
      hsv.h = 60 * (rgb.r - rgb.g) / (max - min) + 240;
    }
  }else{
    if(rgb.g > rgb.b){
      max = rgb.g;
      if(rgb.r > rgb.b){
        min = rgb.b;
        hsv.h = 60 * (rgb.b - rgb.r) / (max - min) + 120;
      }else{
        min = rgb.r;
        hsv.h = 60 * (rgb.b - rgb.r) / (max - min) + 120;
      }
    }else{
      max = rgb.b;
      min = rgb.r;
      hsv.h = 60 * (rgb.r - rgb.g) / (max - min) + 240;
    }
  }
  
  hsv.s = 255 * (max - min) / max;
  hsv.v = max;
} 