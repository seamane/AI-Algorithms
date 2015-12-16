/*
 * Seek.h
 *
 *  Created on: Dec 15, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_SEEK_H_
#define MOVEMENT_SEEK_H_

#include "Kinematic.h"
#include "SteeringOutput.h"

class Seek
{
public:
	Seek();
	~Seek();

	SteeringOutput getSteering();

private:
	Kinematic character;
	Kinematic target;

	float maxAcceleration;
};

#endif /* MOVEMENT_SEEK_H_ */
