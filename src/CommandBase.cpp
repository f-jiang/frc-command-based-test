#include <Subsystems/Drivetrain.h>
#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
std::unique_ptr<Drivetrain> CommandBase::drivetrain;
std::unique_ptr<OI> CommandBase::oi;

CommandBase::CommandBase(const std::string &name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	drivetrain.reset(new Drivetrain());

	oi.reset(new OI());

	SmartDashboard::PutData(drivetrain.get());
}
