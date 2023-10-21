#include "main.h"
#include "lemlib/api.hpp"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void screen() {
    // loop forever
    while (true) {
        lemlib::Pose pose = chassis.getPose(); // get the current position of the robot
        pros::lcd::print(0, "x: %f", pose.x); // print the x position
        pros::lcd::print(1, "y: %f", pose.y); // print the y position
        pros::lcd::print(2, "heading: %f", pose.theta); // print the heading
        pros::delay(10);
    }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	chassis.calibrate();
	sylib::initialize();

	//tasks
	pros::Task screenTask(screen);
	//LIGHTS
	leftDriveLights.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
  	rightDriveLights.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);

	//AUTON SELECTOR
	//pros::lcd::set_text(1, "Hello PROS User!");

	//pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  wings.set_value(false);
  chassis.setPose(-32, -62, 90);
  //drive back to match load
  chassis.moveTo(-48, -62, 1000);
  chassis.turnTo(-23, -48, 500);
  pros::delay(500);
  //match load
  setCataMotors(75);
  pros::delay(35000); //35000
  setCataMotors(0);
  //drive to other side
  chassis.turnTo(0, -60, 500);
  chassis.moveTo(0, -60, 1000);
  chassis.turnTo(35, -60, 200);
  chassis.moveTo(35, -60, 1000);
  chassis.turnTo(35, -46, 500);
  //get near the goal
  chassis.follow("drivetoscore.txt",2000, 15);
  //deploy wings and run into left side of goal
  wings.set_value(true);
  chassis.follow("score1.txt",3000, 15, false, 127);
  wings.set_value(false);
  //back up to middle ~20in infront of goal
  chassis.moveTo(12, 0, 2000);
  //deploy wings and run into middle of goal
  wings.set_value(true);
  chassis.moveTo(45, 0, 2000);
  wings.set_value(false);
  //back up to right side ~20in infront of goal
  chassis.moveTo(9, 16, 2000);
  //deploy wings and run into right side of goal
  wings.set_value(true);
  chassis.follow("score2.txt",3000, 15, false, 127);
  //back up to right side ~20in infront of goal
  wings.set_value(false);
  chassis.moveTo(12, 16, 1000);
  //deploy wings and run into right side of goal again
  wings.set_value(true);
  chassis.moveTo(45, 16, 2000);
  wings.set_value(false);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {
  setDriveLights(0x0fdb35); //green
  bool last30 = false;
  std::uint32_t startTime = pros::millis();
  while (true) {
    std::uint32_t time = pros::millis();

    driveControl();
    setCata();
    setWings();
    setLift();

    if (time-startTime >= 75000 && last30 != true) {
      leftDriveLights.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
      rightDriveLights.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
      controller.rumble(". . . . .");
      last30 = true;
    }

    pros::delay(10); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
