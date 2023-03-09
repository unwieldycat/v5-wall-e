#include "devices.h"

// =========================== Device Definitions =========================== //

// HID & Brain
vex::brain Brain;
vex::controller Controller(vex::controllerType::primary);

// Drivetrain
vex::motor DriveFL(2);
vex::motor DriveFR(12, true);
vex::motor DriveRL(3);
vex::motor DriveRR(13, true);

vex::motor TreadL(1);
vex::motor TreadR(11, true);

vex::motor_group DriveGroupL(DriveFL, DriveRL, TreadL);
vex::motor_group DriveGroupR(DriveRL, DriveRR, TreadR);

// ============================= Drive Program ============================= //

void drive() {
  double controllerX;
  double controllerY;
  bool driving = false;
  while (true) {
    controllerY = Controller.Axis3.position();
    controllerX = Controller.Axis1.position();

    if ((controllerY > 5 || controllerY < -5) ||
        (controllerX > 5 || controllerX < -5)) {
      DriveGroupL.spin(vex::directionType::fwd, controllerY + controllerX,
                       vex::velocityUnits::pct);
      DriveGroupR.spin(vex::directionType::fwd, controllerY - controllerX,
                       vex::velocityUnits::pct);
      driving = true;
    } else if (driving) {
      DriveGroupL.stop();
      DriveGroupR.stop();
      driving = false;
    }
  }
}