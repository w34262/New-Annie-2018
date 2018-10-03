/*
 * catapult.cpp
 *
 *  Created on: Sep 24, 2018
 *      Author: Student
 */
#include "catapult.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

AnnieCatapult::AnnieCatapult()
{
	cataMotor = new Talon(CATA_MOTOR_CHANNEL);
	onePiston = new DoubleSolenoid (release_Piston_1, release_Piston_2);//these are dummy values
	timer = new Timer();
	cataLimit = new DigitalInput(0); //this is a dummy value
}
AnnieCatapult::~AnnieCatapult()
{
	delete cataMotor;
	delete onePiston;
	delete cataLimit;
	delete timer;

	cataMotor = nullptr;
	onePiston = nullptr;
	cataLimit = nullptr;
	timer = nullptr;
}

bool AnnieCatapult::stop()
{
	return cataLimit->Get();
}

void AnnieCatapult:: setlaunchBall(bool lock, bool back)
{
	if((lock) && cataLimit->Get == false)
	{
	onePiston->Set(DoubleSolenoid::kForward);
	cataMotor->Set(ControlMode::PercentOutput, .5);
	}
	if(back)
		{
			onePiston->Set(DoubleSolenoid::kReverse);
		}
	else
	{
	cataMotor->Set(ControlMode::PercentOutput, 0);
	}
}



