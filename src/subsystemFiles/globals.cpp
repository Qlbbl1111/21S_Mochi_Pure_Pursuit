#include "main.h"
#include "pros/adi.h"

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
pros::ADIDigitalIn kickerLimit('H');

// PNUEMATICS
pros::ADIDigitalOut wings('B');
pros::ADIDigitalOut liftLock('E');

// LIGHTS
sylib::Addrled leftDriveLights(16,7,43);
sylib::Addrled rightDriveLights(16,8,43);
sylib::Addrled leftWingLights(16,1,20);
sylib::Addrled rightWingLights(16,2,20);