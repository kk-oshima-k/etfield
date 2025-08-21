#include "Driver.h"

Driver::Driver(DriveController &driveController) : 
  driveController(driveController) {
}

void Driver::stop() {
  driveController.stop();
}
