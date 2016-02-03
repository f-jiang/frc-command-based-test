#include <Commands/ArcadeDriveWithJoystick.h>
#include <Commands/MoveAround.h>
#include <Commands/ChangeHeading.h>
#include <Commands/SetDistance.h>
#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	std::unique_ptr<Command> autonomousCommand;
	SendableChooser *chooser;

	std::unique_ptr<MoveAround> moveAround{new MoveAround()};
	std::unique_ptr<ChangeHeading> changeHeading{new ChangeHeading(360)};
	std::unique_ptr<SetDistance> setDistance{new SetDistance(36)};

	float kP = 0, kI = 0, kD = 0;

	void RobotInit()
	{
		CommandBase::init();

		chooser = new SendableChooser();
		SmartDashboard::PutData("Auto Modes", chooser);

		SmartDashboard::PutData("Move Around", moveAround.get());
		SmartDashboard::PutData("Rotate 360 degrees", changeHeading.get());
		SmartDashboard::PutData("Set dist to 3ft", setDistance.get());
	}

	/**
     * This function is called once each time the robot enters Disabled mode.
     * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
     */
	void DisabledInit()
	{
	}

	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();

		// temp util for tuning PID
		kP = (float) SmartDashboard::GetNumber("DB/Slider 0", 0.0);
		kI = (float) SmartDashboard::GetNumber("DB/Slider 1", 0.0);
		kD = (float) SmartDashboard::GetNumber("DB/Slider 2", 0.0);
		changeHeading->GetPIDController()->SetPID(kP, kI, kD);
		setDistance->GetPIDController()->SetPID(kP, kI, kD);
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to select between different autonomous modes
	 * using the dashboard. The sendable chooser code works with the Java SmartDashboard. If you prefer the LabVIEW
	 * Dashboard, remove all of the chooser code and uncomment the GetString code to get the auto name from the text box
	 * below the Gyro
	 *
	 * You can add additional auto modes by adding additional commands to the chooser code above (like the commented example)
	 * or additional comparisons to the if-else structure below with additional strings & commands.
	 */
	void AutonomousInit()
	{
		autonomousCommand.reset((Command *)chooser->GetSelected());
		CommandBase::drivetrain->Reset();
		autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL) {
			autonomousCommand->Cancel();
		}

		CommandBase::drivetrain->Reset();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		LiveWindow::GetInstance()->Run();
	}
};

START_ROBOT_CLASS(Robot)

