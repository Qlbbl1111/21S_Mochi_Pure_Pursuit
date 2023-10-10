#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

okapi::ControllerButton wingsButton(okapi::ControllerDigital::B);

bool toggle = false;
bool latch = false;

void wingsOff() {
  wings.set_value(false);
}

void wingsOn() {
  wings.set_value(true);
}

void setWings() {
  if (toggle) {
    wings.set_value(true);
    leftWingLights.gradient(0xed310c, 0xeded0c);
    rightWingLights.gradient(0xed310c, 0xeded0c);
  } else {
    wings.set_value(false);
    setWingLights(0x000000);
  }

  if (wingsButton.isPressed()) {
    if (!latch) { // if latch false, toggle one time and set latch true
      toggle = !toggle;
      latch = true;
    }
  } else {
    latch = false; // once button is released then release the latch too
  }
}