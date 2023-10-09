#include "main.h"

// DRIVETRAIN
pros::Motor left_front_motor(19, pros::E_MOTOR_GEARSET_06, true); 
pros::Motor left_back_motor(18, pros::E_MOTOR_GEARSET_06, true); 
pros::Motor left_top_motor(20, pros::E_MOTOR_GEARSET_18, true); 
pros::Motor right_front_motor(12, pros::E_MOTOR_GEARSET_06, false); 
pros::Motor right_back_motor(13, pros::E_MOTOR_GEARSET_06, false); 
pros::Motor right_top_motor(11, pros::E_MOTOR_GEARSET_18, false); 

pros::MotorGroup left_side_motors({left_front_motor, left_back_motor, left_top_motor});
pros::MotorGroup right_side_motors({right_front_motor, right_back_motor, right_top_motor});

// SUBSYSTEMS
pros::Motor cata_a(1, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cata_b(10, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor liftMotor(14, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);

// CONTROLLER
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// SENSORS
pros::Imu inertial(21);

// PNUEMATICS
pros::ADIDigitalOut wings('B');

// LIGHTS
sylib::Addrled leftDriveLights(22,7,52);
sylib::Addrled rightDriveLights(22,8,52);