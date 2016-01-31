#include <Commands/ArcadeDriveWithJoystick.h>
#include <CommandBase.h>

ArcadeDriveWithJoystick::ArcadeDriveWithJoystick() {
	Requires(CommandBase::drivetrain.get());
}

void ArcadeDriveWithJoystick::Initialize() { }

void ArcadeDriveWithJoystick::Execute() {
	Joystick* stick = CommandBase::oi->GetJoystick();
	float moveValue = stick->GetRawAxis(1);
	float rotateValue = stick->GetRawAxis(2);

	CommandBase::drivetrain->Drive(moveValue, rotateValue);
}

bool ArcadeDriveWithJoystick::IsFinished() {
	return false;
}

void ArcadeDriveWithJoystick::End() {
	CommandBase::drivetrain->Drive(0, 0);
}

void ArcadeDriveWithJoystick::Interrupted() {
	End();
}
