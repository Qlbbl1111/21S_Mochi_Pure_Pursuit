#include "main.h"

okapi::ControllerButton cataHold(okapi::ControllerDigital::L2);
okapi::ControllerButton stopCataButton(okapi::ControllerDigital::up);

bool toggleCata = false;
bool latchCata = false;
bool latchCataStop = false;
bool toggleCataStop= false;
bool stopCata = false;

void setCataMotors(int value) {
  if (!stopCata) {
      cata_a = value;
      cata_b = value; 
  } else if (stopCata) {
      cata_a = 0;
      cata_b = 0;
  }
}
bool kickerDown2 = false;
void setCata() {
  cata_a.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  cata_b.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  //Stop Cata Toggle (Up Button)
  if (toggleCataStop) {
    stopCata = true;
  } else {
    stopCata = false;
  }

  if (stopCataButton.isPressed()) {
    if (!latchCataStop) { // if latch false, toggle one time and set latch true
      toggleCataStop = !toggleCataStop;
      latchCataStop = true;
    }
  } else {
    latchCataStop = false; // once button is released then release the latch too
  }
  
  //Cata Toggle (L2 Button)
  if (cataHold.isPressed()) {
    if (!latchCata) { // if latch false, toggle one time and set latch true
      toggleCata = !toggleCata;
      latchCata = true;
    }
  } else {
    latchCata = false; // once button is released then release the latch too
  }

  //Cata Control (L1 for press, L2 for Toggle)
  if (toggleCata ^ controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1) ) {
    //set motors for toggle or press but Dont allow toggle and press
    setCataMotors(80);
    kickerDown2 = false;

  } else {
    //turn off if neither

      if (!kickerLimit.get_value() && !kickerDown2) {
        setCataMotors(80);
      } else {
      kickerDown2 = true;
      setCataMotors(0);
  }
  }

}
  //Over Draw Protection
  //std::cout << "Motor Current Draw: " << cata_a.get_current_draw();
  //if (cata_a.get_current_draw() > 1550) {
   //   stopCata = true;
   // } 