#include "main.h"

void setLift() {
  liftMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        liftMotor = 75;
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        liftMotor = -75;
    } else {
        liftMotor = 0;
}}

okapi::ControllerButton lockButton(okapi::ControllerDigital::X);
bool toggleLock = false;
bool latchLock = false;

void setLock() {
  if (toggleLock) {
    liftLock.set_value(false);
    leftDriveLights.gradient(0x03fcfc, 0xfc03ec, 0, 0, false, true);
    rightDriveLights.gradient(0x03fcfc, 0xfc03ec, 0, 0, false, true);
  } else {
    liftLock.set_value(true);
      leftDriveLights.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
      rightDriveLights.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
  }

  if (lockButton.isPressed()) {
    if (!latchLock) { // if latch false, toggle one time and set latch true
      toggleLock = !toggleLock;
      latchLock = true;
    }
  } else {
    latchLock = false; // once button is released then release the latch too
  }
}