#include "ChangeDistance.h"

ChangeDistance::ChangeDistance(float delta):
	SetDistance(CommandBase::drivetrain->GetHeading() + delta) { }
