/*
 * Flee.h
 *
 *  Created on: Dec 15, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_FLEE_H_
#define MOVEMENT_FLEE_H_

#include "../Kinematics/Kinematic.h"

class Flee {
public:
	Flee();
	virtual ~Flee();

	SteeringOutput getSteering();

//private:
	Kinematic character;
	Kinematic target;

	float maxAcceleration;
};

#endif /* MOVEMENT_FLEE_H_ */
