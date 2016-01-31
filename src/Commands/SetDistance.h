#ifndef SET_DISTANCE_H
#define SET_DISTANCE_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetDistance: public CommandBase
{
private:
	PIDController* pid;

public:
	SetDistance(float distance);

	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

class SetDistancePIDSource: public PIDSource {
public:
	virtual ~SetDistancePIDSource();
	double PIDGet();
};

class SetDistancePIDOutput: public PIDOutput {
public:
	virtual ~SetDistancePIDOutput();
	void PIDWrite(float);
};

#endif
