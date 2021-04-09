#include "vex.h"
#include "pragma.h"

float rotate (motor name) {
  return name.rotation(rotationUnits::raw);
}

void visual_setting () {
  Brain.Screen.setFillColor(black);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setPenWidth(20);
  Brain.Screen.setFont(monoM);
}

float val_lf;
float val_lb;
float val_rf;
float val_rb; 

void visual_update() {
  val_lf = rotate(leftfront);
  val_lb = rotate(leftback);
  val_rf = rotate(rightfront);
  val_rb = rotate(rightback);
}

void visual_print() {
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("Left Front: %f", val_lf);
  Brain.Screen.setCursor(3,1);
  Brain.Screen.print("Left Back: %f", val_lb);
  Brain.Screen.setCursor(5,1);
  Brain.Screen.print("Right Front: %f", val_rf);
  Brain.Screen.setCursor(7,1);
  Brain.Screen.print("Right Back: %f", val_rb);
}