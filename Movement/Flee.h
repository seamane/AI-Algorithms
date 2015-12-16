/*
 * Flee.h
 *
 *  Created on: Dec 15, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_FLEE_H_
#define MOVEMENT_FLEE_H_

#include "Kinematic.h"

class Flee {
public:
	Flee();
	~Flee();

	SteeringOutput getSteering();

private:
	Kinematic character;
	Kinematic target;

	float maxAcceleration;
};

#endif /* MOVEMENT_FLEE_H_ */
