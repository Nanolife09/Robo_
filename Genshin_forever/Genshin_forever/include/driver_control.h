#ifndef DRIVER_CONTROL_H
#define DRIVER_CONTROL_H

#include "vex.h"
#include "pragma.h"

// curve mapping constants
extern bool curve_is_on; // on and off for curved controller mapping
extern double c_exponent;
extern int c_lower_dz; // lower dead zone; dead zone being the part of the joystick range that has no effect
extern int c_upper_dz; // upper dead zone
extern int c_lowest_pwr; // lowest power output
// derived using desmos.com/calculator/rzxfys8ctn -- a calculator I developed for this purpose
extern double c_multiplier;
int c_equation (int axis_input);
void c_mapping_initialize();

extern float A1;
extern float A2;
extern float A3;
extern float A4;

extern void spin (motor name, int power = 100);

extern void tank_control();

extern void intake_v_1();

extern void intake_v_2();

extern void user_control();

extern void button_update();

extern void slow_mode_();

#endif