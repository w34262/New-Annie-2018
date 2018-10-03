/*
 * drive.cpp
 *
 *  Created on: Sep 24, 2018
 *      Author: Student
 */
#include "drive.h"
#include "WPILib.h"
#include "ctre/Phoenix.h"

AnnieDrive::AnnieDrive()
{

	turnSpeed = 0;
	fwdSpeed = 0;

	frontLeftMotor = new Talon(DRIVE_FRONT_LEFT_MOTOR_CHANNEL);
	rearLeftMotor = new Talon(DRIVE_REAR_LEFT_MOTOR_CHANNEL);
	frontRightMotor = new Talon(DRIVE_FRONT_RIGHT_MOTOR_CHANNEL);
	rearRightMotor = new Talon(DRIVE_REAR_RIGHT_MOTOR_CHANNEL);

}

AnnieDrive::~AnnieDrive()
{
	delete frontLeftMotor;
	delete frontRightMotor;
	delete rearLeftMotor;
	delete rearRightMotor;

	frontLeftMotor = nullptr;
	frontRightMotor = nullptr;
	rearLeftMotor = nullptr;
	rearRightMotor = nullptr;
}

void AnnieDrive::drive(float xAxis, float yAxis);
{
	setFwdSpeed(yAxis);
	setTurnSpeed(xAxis);

	updateRightMotors(fwdSpeed);
	updateLeftMotors(fwdSpeed - turnSpeed);
}

void AnnieDrive::updateLeftMotors(float speed)
{
    frontLeftMotor->Set(ControlMode::PercentOutput, -speed);
    rearLeftMotor->Set(ControlMode::PercentOutput, -speed);
}

void AnnieDrive::updateRightMotors(float speed)
{
	frontRightMotor->Set(ControlMode::PercentOutput, speed);
	rearLeftMotor->Set(ControlMode::PercentOutput, speed);
}

void AnnieDrive::setFwdSpeed(float fwd)
{
	if(fwd > 0.2)
	{
		fwdSpeed = (fwd-0.2)*1/.8;
	}

	else if (fwd < -0.2)
	{
		fwdSpeed = (fwd+0,2)*1/.8;
	}

	else
	{
		fwdSpeed = 0;
	}
}

void Drive::setTurnSpeed(float turn)
{
	if(turn > 0.2)
	{
		turnSpeed = (turn-0.2)*1/.8;
	}
	else if (turn < -0.2)
	{
		turnSpeed = (turn+0.2)*1/.8;
	}
	else
	{
		turnSpeed = 0;
	}
}
