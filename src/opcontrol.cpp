#include "main.h"

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
    while ( true ) {
        int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);    // Get left stick input
        int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);  // Get right stick input
        chassis.arcade(leftY, rightX, 2.7);                                     // Use the arcade control style with a turning curve value of 2.7 (higher = more sensitive).
        pros::delay(10);                                                        // Delay each loop by 10 miliseconds since V5 motors only update every 10ms.
    }
}
