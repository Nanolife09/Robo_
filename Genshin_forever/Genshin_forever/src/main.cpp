#include "vex.h"
#include "driver_control.h"
#include "auton_control.h"
#include "visual.h"

using namespace vex;

competition Competition;

void user_control() {
  while (true) {
    tank_control();
    intake_control();
    slow_mode_();
  }
}

int main() {  
  vexcodeInit();
  visual_setting();
  Competition.drivercontrol(user_control);
  Competition.autonomous(Hutao_skill);
  while (true) {
    Brain.Screen.clearScreen();
    button_update();
    visual_update();
    visual_print();
    task::sleep(20);
  }
}