#include "devices.h"

// =========================== Device Definitions =========================== //

// HID & Brain
vex::brain Brain;
vex::controller Controller(vex::controllerType::primary);

// Drivetrain
vex::motor DriveFL(2);
vex::motor DriveFR(12);
vex::motor DriveRL(3);
vex::motor DriveRR(13);

// Fake drive
vex::motor TreadL(1);
vex::motor TreadR(11);
