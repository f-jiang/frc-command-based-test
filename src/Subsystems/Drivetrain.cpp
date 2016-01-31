#include <Subsystems/Drivetrain.h>
#include "../RobotMap.h"
#include "Commands/ArcadeDriveWithJoystick.h"

Drivetrain::Drivetrain():
		Subsystem("Drivetrain"),
		frontLeftMotor(new Victor(FRONT_LEFT_MOTOR)),
		rearLeftMotor(new Victor(REAR_LEFT_MOTOR)),
		frontRightMotor(new Victor(FRONT_RIGHT_MOTOR)),
		rearRightMotor(new Victor(REAR_RIGHT_MOTOR)),
		drive(new RobotDrive(frontLeftMotor, rearLeftMotor, frontRightMotor, rearRightMotor)),
		ultrasonic(new AnalogInput(ULTRASONIC_PORT)),
		gyro(new AnalogGyro(GYRO_PORT))
{
	frontLeftMotor->SetInverted(true);
	rearLeftMotor->SetInverted(true);
	frontRightMotor->SetInverted(true);
	rearRightMotor->SetInverted(true);

	gyro->SetSensitivity(1.6 / 1000);	// 1.6 mV/degree/s
	gyro->Calibrate();

	LiveWindow* lw = LiveWindow::GetInstance();
	lw->AddActuator(GetName(), "Front left motor", frontLeftMotor);
	lw->AddActuator(GetName(), "Rear left motor", rearLeftMotor);
	lw->AddActuator(GetName(), "Front right motor", frontRightMotor);
	lw->AddActuator(GetName(), "Rear right motor", rearRightMotor);
	lw->AddSensor(GetName(), "Ultrasonic", ultrasonic);
	lw->AddSensor(GetName(), "Gyroscope", gyro);
}

void Drivetrain::InitDefaultCommand()
{
	SetDefaultCommand(new ArcadeDriveWithJoystick());
}

void Drivetrain::Drive(float moveValue, float rotateValue) {
	drive->ArcadeDrive(moveValue, rotateValue);
}

void Drivetrain::DriveStraight(float moveValue) {
	drive->Drive(moveValue, 0.4 * GetHeading());
}

float Drivetrain::GetHeading() {	// heading in degrees
	return gyro->GetAngle();
}

float Drivetrain::GetDistance() {	// distance in inches
	return ultrasonic->GetAverageVoltage() * 1000 / 9.8;	// 9.8 mV/in
}

void Drivetrain::Log() {
	SmartDashboard::PutNumber("Front left motor", frontLeftMotor->Get());
	SmartDashboard::PutNumber("Rear left motor", rearLeftMotor->Get());
	SmartDashboard::PutNumber("Front right motor", frontRightMotor->Get());
	SmartDashboard::PutNumber("Rear right motor", rearRightMotor->Get());
	SmartDashboard::PutNumber("Ultrasonic distance (in)", GetDistance());
	SmartDashboard::PutNumber("Gyro angle", GetHeading());
	SmartDashboard::PutNumber("Gyro rate", gyro->GetRate());
}

void Drivetrain::Reset() {
	gyro->Reset();
}

