/*
 * catapult.h
 *
 *  Created on: Sep 24, 2018
 *      Author: Student
 */

#ifndef CATAPULT_H_
#define CATAPULT_H_

#include "WPILib.h"
#include "ctre/Phoenix.h"
#include "macros.h"

class AnnieCatapult
{
public:
	AnnieCatapult();
	~AnnieCatapult();

	void setlaunchBall (bool lock, bool back);
	bool stop();


private:
	Talon *cataMotor;
	DoubleSolenoid * onePiston;
	Timer* timer;
	DigitalInput * cataLimit;

};



#endif /* CATAPULT_H_ */
