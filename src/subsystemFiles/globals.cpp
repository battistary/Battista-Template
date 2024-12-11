#include "main.h"

// Variables
int auton = 1;

// Controllers
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// Motors
pros::Motor driveLeftFront(-1, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveMiddleLeft(-2, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveLeftBack(-3, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveRightFront(4, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveMiddleRight(5, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor driveRightBack(6, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::Motor intake(7, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);

// Motor Groups
pros::MotorGroup driveLeft({-1, -2, -3}, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);
pros::MotorGroup driveRight({4, 5, 6}, pros::v5::MotorGears::blue, pros::v5::MotorUnits::counts);

// Sensors
pros::Imu imu(8);

// Drivetrain constructor
lemlib::Drivetrain drivetrain(
    &driveLeft,                 // Left drivetrain motors
    &driveRight,                // Right drivetrain motors
    11,                         // 11 inch track width
    lemlib::Omniwheel::NEW_275, // 2.75" wheel diameter
    450,                        // 450 RPM drivetrain
    2                           // Chase power = 2 (default)
);

// Lateral motion controller
lemlib::ControllerSettings lateralController(
    20,     // kP
    0,      // kI
    20,     // kD
    0,      // anti windup
    1,      // smallErrorRange
    100,    // smallErrorTimeout
    3,      // largeErrorRange
    500,    // largeErrorTimeout
    26      // slew rate (max acceleration)
);
 
// Angular motion controller
lemlib::ControllerSettings angularController(
    5,      // kP
    0,      // kI
    47,     // kD
    3,      // anti windup
    1,      // smallErrorRange
    100,    // smallErrorTimeout
    3,      // largeErrorRange
    500,    // largeErrorTimeout
    0       // slew rate (max acceleration)
);

// Odometry constructor
lemlib::OdomSensors sensors(
    nullptr, // N/A - vertical tracking wheel 1
    nullptr, // N/A - vertical tracking wheel 2
    nullptr, // N/A - horizontal tracking wheel 1
    nullptr, // N/A - hortizontal tracking wheel 2
    &imu     // inertial sensor
);

// Create chassis object
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);
