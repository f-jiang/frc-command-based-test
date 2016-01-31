#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Drivetrain: public Subsystem
{
private:
	std::shared_ptr<Victor> frontLeftMotor;
	std::shared_ptr<Victor> rearLeftMotor;
	std::shared_ptr<Victor> frontRightMotor;
	std::shared_ptr<Victor> rearRightMotor;

	std::shared_ptr<RobotDrive> drive;
	std::shared_ptr<AnalogInput> ultrasonic;
	std::shared_ptr<AnalogGyro> gyro;
public:
	Drivetrain();

	void InitDefaultCommand();
	void Drive(float, float);
	void DriveStraight(float);
	float GetHeading();
	float GetDistance();
	void Log();
	void Reset();
};

#endif
