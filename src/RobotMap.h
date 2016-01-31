#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
const int FRONT_LEFT_MOTOR = 3;
const int REAR_LEFT_MOTOR = 2;
const int FRONT_RIGHT_MOTOR = 1;
const int REAR_RIGHT_MOTOR = 0;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
const int ULTRASONIC_PORT = 0;
const int GYRO_PORT = 1;

#endif
