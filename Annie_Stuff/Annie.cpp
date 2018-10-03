/*
 * Annie.cpp
 *
 *  Created on: Oct 1, 2018
 *      Author: Student
 */
#include <iostream>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include <drive.h>
#include <manipulator.h>
#include <catapult.h>

class Robot : public frc::IterativeRobot {
public:
	AnnieCatapult* catapult;
	AnnieManipulator* manipulator;
	AnnieDrive* drive;
	Joystick* xbox;
	void RobotInit() {
		drive = new AnnieDrive();
		manipulator = new AnnieManipulator();
		catapult = new AnnieCatapult();
		xbox = new Joystick(0);
		Compressor *comp599 = new Compressor();0
		comp599->SetClosedLoopControl(true);
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to
	 * select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to
	 * the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as
	 * well.
	 */
	void AutonomousInit() override {
		m_autoSelected = m_chooser.GetSelected();
		// m_autoSelected = SmartDashboard::GetString(
		// 		"Auto Selector", kAutoNameDefault);
		std::cout << "Auto selected: " << m_autoSelected << std::endl;

		if (m_autoSelected == kAutoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void AutonomousPeriodic() {
		if (m_autoSelected == kAutoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void TeleopInit() {}

	void TeleopPeriodic()
	{
		drive->drive(xbox->GetRawAxis(1), xbox->GetRawAxis(2));
		catapult->setlaunchBall(xbox->GetRawButton(1),xbox->GetRawButton(6));
		manipulator->intakeBall(xbox->GetRawButton(2));
		manipulator->initialPos(xbox->GetRawButton(4),xbox->GetRawButton(5));
		SmartDashboard::GetBoolean("stopper:", catapult->stop());
	}

	void TestPeriodic() {}

private:
	frc::LiveWindow& m_lw = *LiveWindow::GetInstance();
	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";
	std::string m_autoSelected;
};

START_ROBOT_CLASS(Robot)


