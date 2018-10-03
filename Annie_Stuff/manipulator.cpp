/*
 * manipulaor.cpp
 *
 *  Created on: Sep 24, 2018
 *      Author: Student
 */
#include "manipulator.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

AnnieManipulator::AnnieManipulator()
{
	oneMotor = new Talon (MANIP_MOTOR_CHANNEL);
	leftPiston = new DoubleSolenoid (intake_Piston_1, intake_Piston_2); //these are dummy values
	rightPiston = new DoubleSolenoid (intake_Piston_1, intake_Piston_2); //these are dummy values
}

AnnieManipulator::~AnnieManipulator()
{
    delete oneMotor;
    delete leftPiston;
    delete rightPiston;

    oneMotor = nullptr;
    leftPiston = nullptr;
    rightPiston = nullptr;
}

void AnnieManipulator::intakeBall(bool intake)
{
	if (intake)
	{
		oneMotor->Set(ControlMode::PercentOutput, .8);
	}
	else
	{
		oneMotor->Set(ControlMode::PercentOutput, 0);
	}
}

void AnnieManipulator::initialPos(bool reverse, bool fwd)
{
	if (fwd)
	{
		leftPiston->Set(DoubleSolenoid::kForward);
		rightPiston->Set(DoubleSolenoid::kForward);
	}
	else if (reverse)
	{
		leftPiston->Set(DoubleSolenoid::kReverse);
		rightPiston->Set(DoubleSolenoid::kReverse);
	}
}
