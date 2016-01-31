#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* joystick;
public:
	OI();

	Joystick* GetJoystick();
};

#endif
