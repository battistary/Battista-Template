#include "main.h"

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
    if ( auton == 1 ) {
        /*---------------*/
        /* EXAMPLE AUTON */
        /*---------------*/

        chassis.setPose(0, 0, 0);           // Start
        chassis.moveToPoint(0, 24, 1000);   // Move forewards 24 inches with a 1 second timeout
        chassis.turnToPoint(24, 24, 500);   // Turn to face point (24, 24) with a 500 milisecond timeout
        chassis.waitUntilDone();            // Wait until the chassis object reports that it has stopped moving
        pros::delay(500);                   // Wait 500 milliseconds
        pros::lcd::set_text(0, "Finished!");// Print "Finished!" on the brain screen
    }

    else if ( auton == 2 ) {
        // Code your next auton here
    }

    else if ( auton == 3 ) {
        // Code your next auton here
    }
}
