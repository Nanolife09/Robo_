#include "driver_control.h"

controller ctrl;

// curve mapping constants
bool curve_is_on = 1; // on and off for curved controller mapping
double c_exponent = 2.0;
int c_lower_dz = 10; // lower dead zone; dead zone being the part of the joystick range that has no effect
int c_upper_dz = 10; // upper dead zone
int c_lowest_pwr = 3; // lowest power output
// derived using desmos.com/calculator/rzxfys8ctn -- a calculator I developed for this purpose
double c_multiplier = 0;
// math for the mapping
int c_equation (int axis_input)
{
  if (abs(axis_input) >= 127 - c_upper_dz) { return copysign(100, axis_input); }
  else if (abs(axis_input) <= c_lower_dz) { return 0; }
  else { return int(copysign(round(c_multiplier * pow(abs(axis_input) - c_lower_dz, c_exponent)) + c_lowest_pwr, axis_input)); }
}
// initiaizing the mapping constant
void c_mapping_initialize() { c_multiplier = (100 - c_lowest_pwr) / pow(127 - (c_upper_dz + c_lower_dz), c_exponent); }

float slow_mode = 1;

float A1 = 0;
float A2 = 0;
float A3 = 0;
float A4 = 0;

bool R1 = (ctrl.ButtonR1.pressing()) ? true : false;
bool R2 = (ctrl.ButtonR2.pressing()) ? true : false;
bool L1 = (ctrl.ButtonL1.pressing()) ? true : false;
bool L2 = (ctrl.ButtonL2.pressing()) ? true : false;

void spin (motor name, int power) {
  name.spin(directionType::fwd, power, velocityUnits::pct);
}

void tank_control() {
  spin(leftfront, c_equation(A3) * slow_mode);
  spin(leftback, c_equation(A3) * slow_mode);
  spin(rightfront, c_equation(A2) * slow_mode);
  spin(rightback, c_equation(A2) * slow_mode);
}

void intake_control() {
  if (R1) {
    spin(h_intake_r);
    spin(h_intake_l);
    spin(v_intake_bottom);
  }
  else if (L2) {
    spin(h_intake_r, -100);
    spin(h_intake_l, -100);
    spin(v_intake_bottom, -100);
  }
  else {
    v_intake_bottom.stop();
    h_intake_r.stop();
    h_intake_l.stop();
  }
  if (R2) {
    spin(v_intake_top);
  }
  else {
    v_intake_top.stop();
  }
}

void slow_mode_ () {
  if (L1) {
    slow_mode = 0.7;
  }
  else {
    slow_mode = 1;
  }
}

void button_update() {
  A1 = ctrl.Axis1.value();
  A2 = ctrl.Axis2.value();
  A3 = ctrl.Axis3.value();
  A4 = ctrl.Axis4.value();
  R1 = (ctrl.ButtonR1.pressing()) ? true : false;
  R2 = (ctrl.ButtonR2.pressing()) ? true : false;
  L1 = (ctrl.ButtonL1.pressing()) ? true : false;
  L2 = (ctrl.ButtonL2.pressing()) ? true : false;
}