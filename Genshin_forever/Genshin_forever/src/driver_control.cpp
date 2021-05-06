#include "driver_control.h"

controller ctrl;

float slow_mode = 1;

float A1 = 0;
float A2 = 0;
float A3 = 0;
float A4 = 0;

bool R1 = (ctrl.ButtonR1.pressing()) ? true : false;
bool R2 = (ctrl.ButtonR2.pressing()) ? true : false;
bool L1 = (ctrl.ButtonL1.pressing()) ? true : false;
bool L2 = (ctrl.ButtonL2.pressing()) ? true : false;
bool UP = (ctrl.ButtonUp.pressing()) ? true : false;

void spin (motor name, int power) {
  name.spin(directionType::fwd, power, velocityUnits::pct);
}

void tank_control() {
  spin(leftfront, A3 * slow_mode);
  spin(leftback, A3 * slow_mode);
  spin(rightfront, A2 * slow_mode);
  spin(rightback, A2 * slow_mode);
}

void intake_v_1() {
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

void intake_v_2() {
  if (R1) {
    spin(h_intake_r);
    spin(h_intake_l);
  }
  if (R2) {
    spin(v_intake_top);
    spin(v_intake_bottom);
  }
  if (L1) {
    spin(h_intake_r, -100);
    spin(h_intake_l, -100);
  }
  if (L2) {
    spin(v_intake_bottom, -100);
  }
  if (UP) {
    spin(v_intake_top, -100);
  }
  if (!R1 && !L1) {
    h_intake_r.stop();
    h_intake_l.stop();
  }
  if (!R2) {
    if (!L2) {
      v_intake_bottom.stop();
    }
    if (!UP) {
      v_intake_top.stop();
    }
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
  UP = (ctrl.ButtonUp.pressing()) ? true : false;
}