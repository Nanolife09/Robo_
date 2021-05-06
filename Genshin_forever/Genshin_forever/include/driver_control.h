#ifndef DRIVER_CONTROL_H
#define DRIVER_CONTROL_H

#include "vex.h"
#include "pragma.h"

extern void spin (motor name, int power = 100);

extern void tank_control();

extern void intake_v_1();

extern void intake_v_2();

extern void user_control();

extern void button_update();

extern void slow_mode_();

#endif