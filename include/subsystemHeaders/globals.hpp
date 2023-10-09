#include "main.h"

// DRIVETRAIN
extern pros::Motor left_front_motor;
extern pros::Motor left_back_motor;
extern pros::Motor left_top_motor;
extern pros::Motor right_front_motor;
extern pros::Motor right_back_motor;
extern pros::Motor right_top_motor;

extern pros::MotorGroup left_side_motors;
extern pros::MotorGroup right_side_motors;

// SUBSYSTEMS
extern pros::Motor cata_a;
extern pros::Motor cata_b;
extern pros::Motor liftMotor;

// CONTROLLER
extern pros::Controller controller;

// SENSORS
extern pros::Imu inertial;

// PNUEMATICS
extern pros::ADIDigitalOut wings;

// LIGHTS
extern sylib::Addrled leftDriveLights;
extern sylib::Addrled rightDriveLights;
