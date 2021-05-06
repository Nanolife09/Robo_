#include "vex.h"
#include "pragma.h"
#include "driver_control.h"
#include "auton_control.h"
#include <vector>
#include <chrono>
#include <iostream>

float constant = 0.001;
float power;

void forward_ (float rotate) {
  while (rightfront.rotation(rotationUnits::raw) < rotate) {
    power = rotate - rightfront.rotation(rotationUnits::raw);
    if (power >= 100) {
      power = 100;
    }
    rightfront.spin(directionType::fwd, power, velocityUnits::pct);
    rightback.spin(directionType::fwd, power, velocityUnits::pct);
    leftfront.spin(directionType::fwd, power, velocityUnits::pct);
    leftback.spin(directionType::fwd, power, velocityUnits::pct);
    h_intake_r.spin(directionType::fwd, 100, velocityUnits::pct);
    h_intake_l.spin(directionType::fwd, 100, velocityUnits::pct);
    v_intake_bottom.spin(directionType::fwd, 100, velocityUnits::pct);
  }
  h_intake_r.stop();
  h_intake_l.stop();
  v_intake_bottom.stop();
  rightfront.rotateTo(rotate, rotationUnits::raw);
  rightback.rotateTo(rotate, rotationUnits::raw);
  leftfront.rotateTo(rotate, rotationUnits::raw);
  leftback.rotateTo(rotate, rotationUnits::raw);
}

void backward_ (float rotate) {
  while (rightfront.rotation(rotationUnits::raw) < rotate) {
    power = rotate - rightfront.rotation(rotationUnits::raw);
    if (power <= -100) {
      power = -100;
    }
    rightfront.spin(directionType::fwd, power, velocityUnits::pct);
    rightback.spin(directionType::fwd, power, velocityUnits::pct);
    leftfront.spin(directionType::fwd, power, velocityUnits::pct);
    leftback.spin(directionType::fwd, power, velocityUnits::pct);
  }
  rightfront.rotateTo(rotate, rotationUnits::raw);
  rightback.rotateTo(rotate, rotationUnits::raw);
  leftfront.rotateTo(rotate, rotationUnits::raw);
  leftback.rotateTo(rotate, rotationUnits::raw);
}

void full_cycle (int time) {
  h_intake_r.spin(directionType::fwd, 100, velocityUnits::pct);
  h_intake_l.spin(directionType::fwd, 100, velocityUnits::pct);
  v_intake_top.spin(directionType::fwd, 100, velocityUnits::pct);
  v_intake_bottom.spin(directionType::fwd, 100, velocityUnits::pct);
  task::sleep(time);
}

void Hutao_skill() {
  forward_(1000);
  full_cycle(1000);
  backward_(1000);
} 
