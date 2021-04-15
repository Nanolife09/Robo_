#include "vex.h"
#include "pragma.h"
#include "driver_control.h"
#include "auton_control.h"
#include <vector>
#include <chrono>
#include <iostream>

float constant = 0.001;

void right_movement (float target, bool intake = true) {
  if (target > 0) {
    while (rightfront.rotation(rotationUnits::raw) < target) {
      float power = target - rightfront.rotation(rotationUnits::raw);
      if (power >= 100) {
        power = 100;
      }
      else if (power <= -100) {
        power = -100;
      }
      spin(rightfront, power * constant);
      spin(rightback, power * constant);
      if (intake) {
        spin(h_intake_r);
        spin(h_intake_l);
        spin(v_intake_bottom);
      }
    }
  }
  else {
    while (rightfront.rotation(rotationUnits::raw) > target) {
      float power = target + rightfront.rotation(rotationUnits::raw);
      if (power >= 100) {
        power = 100;
      }
      else if (power <= -100) {
        power = -100;
      }
      spin(rightfront, power * constant);
      spin(rightback, power * constant);
      if (intake) {
        spin(h_intake_r);
        spin(h_intake_l);
        spin(v_intake_bottom);
      }
    }
  }
  rightfront.stop();
  rightback.stop();
  if (intake) {
    h_intake_r.stop();
    h_intake_l.stop();
    v_intake_bottom.stop();
  }
}

void left_movement (float target, bool intake = true) {
  if (target > 0) {
    while (leftfront.rotation(rotationUnits::raw) < target) {
      float power = target - leftfront.rotation(rotationUnits::raw);
      if (power >= 100) {
        power = 100;
      }
      else if (power <= -100) {
        power = -100;
      }
      spin(leftfront, power * constant);
      spin(leftback, power * constant);
      if (intake) {
        spin(h_intake_r);
        spin(h_intake_l);
        spin(v_intake_bottom);
      }
    }
  }
  else {
    while (leftfront.rotation(rotationUnits::raw) > target) {
      float power = target + leftfront.rotation(rotationUnits::raw);
      if (power >= 100) {
        power = 100;
      }
      else if (power <= -100) {
        power = -100;
      }
      spin(leftfront, power * constant);
      spin(leftback, power * constant);
      if (intake) {
        spin(h_intake_r);
        spin(h_intake_l);
        spin(v_intake_bottom);
      }
    }
  }
  leftfront.stop();
  leftback.stop();
  if (intake) {
    h_intake_r.stop();
    h_intake_l.stop();
    v_intake_bottom.stop();
  }
}

std::vector <std::vector<float>> route;
std::vector <bool> intake_permission;

void test () {
  std::cout << "running...";
}

void Hutao_skill() {
  std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
  thread t1 ([]{test();});
  thread t2 ([]{test();});
  t1.join();
  t2.join();
  std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
  //test();
  //test();
  std::chrono::seconds total_time = std::chrono::duration_cast<std::chrono::seconds>(end - begin);
  std::cout << "time: " << total_time.count();
} 
