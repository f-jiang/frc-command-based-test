#ifndef SET_HEADING_H
#define SET_HEADING_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetHeading: public CommandBase
{
private:
	PIDController* pid;

public:
	SetHeading(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	PIDController* GetPIDController();	// temp
};

class SetHeadingPIDSource: public PIDSource {
public:
	virtual ~SetHeadingPIDSource();
	double PIDGet();
};

class SetHeadingPIDOutput: public PIDOutput {
public:
	virtual ~SetHeadingPIDOutput();
	void PIDWrite(float);
};

#endif
