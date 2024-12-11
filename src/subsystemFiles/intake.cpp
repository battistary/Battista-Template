#include "main.h"

// Example intake subsystem file

void setIntake() {
    while ( true ) {
        intake.move(127 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1) - controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)));
        pros::delay(10);
    }
}
