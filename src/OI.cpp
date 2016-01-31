#include "OI.h"

OI::OI()
{
	joystick = new Joystick(0);
}

Joystick* OI::GetJoystick() {
	return joystick;
}
