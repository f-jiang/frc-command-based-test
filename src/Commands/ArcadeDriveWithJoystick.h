#ifndef ARCADE_DRIVE_WITH_JOYSTICK
#define ARCADE_DRIVE_WITH_JOYSTICK

#include "../CommandBase.h"
#include "WPILib.h"

class ArcadeDriveWithJoystick: public CommandBase
{
public:
	ArcadeDriveWithJoystick();

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
