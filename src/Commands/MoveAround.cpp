#include "MoveAround.h"
#include "ChangeDistance.h"
#include "ChangeHeading.h"

MoveAround::MoveAround()
{
	AddSequential(new ChangeHeading(360));
	AddSequential(new ChangeDistance(36));
	AddSequential(new ChangeHeading(180));
	AddSequential(new ChangeDistance(36));
	AddSequential(new ChangeHeading(180));
}
