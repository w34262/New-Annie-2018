/*
 * manipulator.h
 *
 *  Created on: Sep 24, 2018
 *      Author: Student
 */

#ifndef MANIPULATOR_H_
#define MANIPULATOR_H_

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "macros.h"

class AnnieManipulator
{
public:
	AnnieManipulator();
	~AnnieManipulator();

	void intakeBall (bool intake);
	void initialPos (bool reverse, bool fwd);

private:

	Talon *oneMotor;
	DoubleSolenoid* leftPiston;
	DoubleSolenoid* rightPiston;
};



#endif /* MANIPULATOR_H_ */
