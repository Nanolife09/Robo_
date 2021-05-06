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

void visual_print() {
  Brain.Screen.setCursor(1,1);
  Brain.Screen.print("Left Front: %f", leftfront.rotation(rotationUnits::raw));
  Brain.Screen.setCursor(3,1);
  Brain.Screen.print("Left Back: %f", leftback.rotation(rotationUnits::raw));
  Brain.Screen.setCursor(5,1);
  Brain.Screen.print("Right Front: %f", rightfront.rotation(rotationUnits::raw));
  Brain.Screen.setCursor(7,1);
  Brain.Screen.print("Right Back: %f", rightback.rotation(rotationUnits::raw));
}