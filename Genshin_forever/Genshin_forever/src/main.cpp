#include "vex.h"
#include "driver_control.h"
#include "auton_control.h"
#include "visual.h"

using namespace vex;

competition Competition;

void user_control() {
  int graph[255];

  for (int i = 0; i < 255; i++) {
    graph[i] = c_equation(i - 127);
  }

  for (int i = 0; i < 255; i++) {
    std::cout << (i - 127) << " " << graph[i] << std::endl;
  }

  while (true) {
    tank_control();
    intake_control();
    slow_mode_();

    std::cout << A3 << std::endl;
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