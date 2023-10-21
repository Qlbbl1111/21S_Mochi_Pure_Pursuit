#include "main.h"
#include "lemlib/api.hpp"

//Runs a P loop on the drive when the joysticks are released.
int curve(int input) {
    double t = 7;
    return (exp(-(t/10))+exp((abs(input)-100)/10)*(1- exp(-(t/10))))*input;
}

void driveControl() {
    double kP = 0.03;
    if (abs(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y)) < 5) {
        left_side_motors = (0 - left_front_motor.get_position()) * kP;
    } else {
        left_front_motor.tare_position();
        left_side_motors = curve(controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
    }
    
    if (abs(controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y)) < 5) {
        right_side_motors = (0 - right_front_motor.get_position()) * kP;
    } else {
    right_front_motor.tare_position();
    right_side_motors = curve(controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y));
    }
}

lemlib::Drivetrain_t drivetrain {
    &left_side_motors, // left drivetrain motors
    &right_side_motors, // right drivetrain motors
    13.25, // track width
    4.125, // wheel diameter
    300 // wheel rpm
};

// odometry struct
lemlib::OdomSensors_t sensors {
    nullptr, // vertical tracking wheel 1
    nullptr, // vertical tracking wheel 2
    nullptr, // horizontal tracking wheel 1
    nullptr, // we don't have a second tracking wheel, so we set it to nullptr
    &inertial // inertial sensor
};
 
// forward/backward PID
lemlib::ChassisController_t lateralController {
    15, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    15, // kP
    80, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    40 // slew rate
};
 
 
// create the chassis
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);