/*
 * Arrive.h
 *
 *  Created on: Dec 15, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_ARRIVE_H_
#define MOVEMENT_ARRIVE_H_

#include "Kinematic.h"

class Arrive {
public:
	Arrive();
	~Arrive();

	SteeringOutput getSteering();

private:
	Kinematic character;
	Kinematic target;
	float maxAcceleration;
	float maxSpeed;
	float targetRadius;
	float slowRadius;
	float timeToTarget = 0.1f;

};

#endif /* MOVEMENT_ARRIVE_H_ */
