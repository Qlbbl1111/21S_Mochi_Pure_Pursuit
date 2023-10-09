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