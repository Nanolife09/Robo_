#include "vex.h"
#include "pragma.h"
#include "auton_control.h"

const float fb_constant = 0.1;
const float t_constant = 0;
float power = 0;

void intake(int time) {
  v_intake_bottom.spin(directionType::fwd, 100, velocityUnits::pct);
  h_intake_r.spin(directionType::fwd, 100, velocityUnits::pct);
  h_intake_l.spin(directionType::fwd, 100, velocityUnits::pct);
  task::sleep(time);
  v_intake_bottom.stop();
  h_intake_r.stop();
  h_intake_l.stop();
}

void outtake(int time) { 
  v_intake_top.spin(directionType::fwd, 100, velocityUnits::pct);
  task::sleep(time);
  v_intake_top.stop();
}

void v_intake_only (int time) {
  v_intake_bottom.spin(directionType::fwd, 100, velocityUnits::pct);
  v_intake_top.spin(directionType::fwd, 100, velocityUnits::pct);
  task::sleep(time);
}

void full_cycle(int time) {
  v_intake_top.spin(directionType::fwd, 100, velocityUnits::pct);
  v_intake_bottom.spin(directionType::fwd, 100, velocityUnits::pct);
  h_intake_r.spin(directionType::fwd, 100, velocityUnits::pct);
  h_intake_l.spin(directionType::fwd, 100, velocityUnits::pct);
  task::sleep(time);
  v_intake_top.stop();
  v_intake_bottom.stop();
  h_intake_r.stop();
  h_intake_l.stop();
}

void right(float rotation) {
  while (rightfront.rotation(rotationUnits::raw) < rotation) {
    power = (rotation - rightfront.rotation(rotationUnits::raw)) * t_constant;
    if (power > 100) {
      power = 100;
    }
    rightfront.spin(directionType::fwd, power, velocityUnits::pct);
    rightback.spin(directionType::fwd, power, velocityUnits::pct);
    leftfront.spin(directionType::fwd, -power, velocityUnits::pct);
    leftback.spin(directionType::fwd, -power, velocityUnits::pct);
  }
  rightfront.stop();
  rightback.stop();
  leftfront.stop();
  leftback.stop();
}

void left(float rotation) {
  while (leftfront.rotation(rotationUnits::raw) > rotation) {
    power = (rotation - rightfront.rotation(rotationUnits::raw)) * t_constant;
    if (power > 100) {
      power = 100;
    }
    rightfront.spin(directionType::fwd, -power, velocityUnits::pct);
    rightback.spin(directionType::fwd, -power, velocityUnits::pct);
    leftfront.spin(directionType::fwd, power, velocityUnits::pct);
    leftback.spin(directionType::fwd, power, velocityUnits::pct);
  }
  rightfront.stop();
  rightback.stop();
  leftfront.stop();
  leftback.stop();
}

void forward_and_intake(float rotation) {
  while (rightfront.rotation(rotationUnits::raw) < rotation) {
    power = (rotation - rightfront.rotation(rotationUnits::raw)) * fb_constant;
    if (power > 100) {
      power = 100;
    }
    if (leftfront.rotation(rotationUnits::raw) <= rotation) {
      leftfront.stop();
      leftback.stop();
    }
    else {
      leftfront.spin(directionType::fwd, power, velocityUnits::pct);
      leftback.spin(directionType::fwd, power, velocityUnits::pct);
    }
    rightfront.spin(directionType::fwd, power, velocityUnits::pct);
    rightback.spin(directionType::fwd, power, velocityUnits::pct);
    v_intake_bottom.spin(directionType::fwd, 100, velocityUnits::pct);
    h_intake_r.spin(directionType::fwd, 100, velocityUnits::pct);
    h_intake_l.spin(directionType::fwd, 100, velocityUnits::pct);
  }
  rightfront.stop();
  rightback.stop();
  leftfront.stop();
  leftback.stop();
  v_intake_bottom.stop();
  h_intake_r.stop();
  h_intake_l.stop();
}


void pre_auton() {
  
}

void Hutao_skill() {
  forward_and_intake(1000);
  /* red
    forward_and_intake(rotation);
    left(rotation);
    forward_and_intake(rotation);
    left(rotaion);
    forward_and_intake(rotation);
    full_cycle(time);
  */
  /* orange
    backward(rotation);
    outtake(time);
    left(rotation);
    forward_and_intake(rotation);
    left(rotation);
    forward_and_intake(rotation);
    full_cycle(time);
  */
  /* yellow
    backward(rotation);
    right(rotation);
    forward_and_intake(rotation);
    left(rotation);
    forward_and_intake(rotation);
    full_cycle(time);
  */
  /* lime
    backward(rotation);
    full_cycle(time);
    right(rotation);
    forward_and_intake(rotation);
    left(rotation);
    forward_and_intake(rotation);
    full_cycle(time);
  */
  /* light blue
    backward(rotation);
    full_cycle(time);
    left(rotation);
    forward_and_intake(rotation);
    full_cycle(time);
  */
  /* blue
    backward(rotation);
    full_cycle(time);
    right(rotation);
    forward_and_intake(rotation);
    full_cycle(time);
  */
  /* purple
    backward(rotation);
    full_cycle(time);
    right(rotation);
    forward_and_intake(rotation);
    right(rotation);

  */
  /*`light grey

  */
}
