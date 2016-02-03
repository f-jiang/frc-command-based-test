#include <Commands/SetDistance.h>

SetDistance::SetDistance(float distance) :	// distance in inches
	pid(new PIDController(-0.1, 0, 0, new SetDistancePIDSource(), new SetDistancePIDOutput()))
{
	Requires(CommandBase::drivetrain.get());

	pid->SetAbsoluteTolerance(0.01);
	pid->SetSetpoint(distance);
}

void SetDistance::Initialize() {
	pid->Reset();
	pid->Enable();
}

void SetDistance::Execute() { }

bool SetDistance::IsFinished() {
	return pid->OnTarget();
}

void SetDistance::End()
{
	pid->Disable();
	CommandBase::drivetrain->Drive(0, 0);
}

void SetDistance::Interrupted()
{
	End();
}

// temp
PIDController* SetDistance::GetPIDController() {
	return pid;
}

SetDistancePIDSource::~SetDistancePIDSource() { }

double SetDistancePIDSource::PIDGet() {
	return CommandBase::drivetrain->GetDistance();
}

SetDistancePIDOutput::~SetDistancePIDOutput() { }

void SetDistancePIDOutput::PIDWrite(float d) {
	CommandBase::drivetrain->Drive(d, 0);
}
