#include "vex.h"

// ========================== Device Declarations ========================== //

// HID & Brain
extern vex::brain Brain;
extern vex::controller Controller;

// Drivetrain
extern vex::motor DriveFL;
extern vex::motor DriveFR;
extern vex::motor DriveRL;
extern vex::motor DriveRR;

extern vex::motor TreadL;
extern vex::motor TreadR;

extern vex::motor_group DriveGroupL;
extern vex::motor_group DriveGroupR;

void drive();