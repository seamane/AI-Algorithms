/*
 * Align.h
 *
 *  Created on: Dec 16, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_ALIGN_H_
#define MOVEMENT_ALIGN_H_

#include "../Kinematics/Kinematic.h"
#include "SteeringOutput.h"

class Align {
public:
	Align();
	~Align();

	SteeringOutput getSteering();
	float mapToRange(float);

private:
	Kinematic character;
	Kinematic target;
	float maxRotation;
	float maxAngularAcceleration;
	float targetRadius;
	float slowRadius;
	float timeToTarget = 0.1f;
};

#endif /* MOVEMENT_ALIGN_H_ */
