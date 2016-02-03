#include <Commands/SetHeading.h>

SetHeading::SetHeading(float heading):	// heading in degrees
	pid(new PIDController(-0.01, -0.01, -0.15, new SetHeadingPIDSource(), new SetHeadingPIDOutput()))
{
	Requires(CommandBase::drivetrain.get());

	pid->SetOutputRange(-0.8, 0.8);
	pid->SetAbsoluteTolerance(0.01);
	pid->SetSetpoint(heading);
}

void SetHeading::Initialize() {
	pid->Reset();
	pid->Enable();
}

void SetHeading::Execute() { }

bool SetHeading::IsFinished() {
	return pid->OnTarget();
}

void SetHeading::End()
{
	pid->Disable();
	CommandBase::drivetrain->Drive(0, 0);
}

void SetHeading::Interrupted()
{
	End();
}

SetHeadingPIDSource::~SetHeadingPIDSource() { }

double SetHeadingPIDSource::PIDGet() {
	return CommandBase::drivetrain->GetHeading();
}

SetHeadingPIDOutput::~SetHeadingPIDOutput() { }

void SetHeadingPIDOutput::PIDWrite(float r) {
	CommandBase::drivetrain->Drive(0, r);
}

