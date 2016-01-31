#include "ChangeHeading.h"

ChangeHeading::ChangeHeading(float delta):
	SetHeading(CommandBase::drivetrain->GetHeading() + delta) { }
