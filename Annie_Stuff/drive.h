/*
 * drive.h
 *
 *  Created on: Sep 24, 2018
 *      Author: Student
 */
#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "macros.h"

class AnnieDrive
{
public:
	AnnieDrive();
	~AnnieDrive();

	void drive(float xAxis, float yAxis);
    void updateLeftMotors(float speed);
    void updateRightMotors(float speed);
    void setFwdSpeed(float fwd);
    void setTurnSpeed(float turn);

private:
	Talon *frontLeftMotor;
	Talon *rearLeftMotor;
	Talon *frontRightMotor;
	Talon *rearRightMotor;

	float fwdSpeed;
	float turnSpeed;
};
