/*
 * SteeringOutput.h
 *
 *  Created on: Dec 11, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_STEERINGOUTPUT_H_
#define MOVEMENT_STEERINGOUTPUT_H_

#include "../VectorOrPoint.h"

struct SteeringOutput
{
	VectorOrPoint linear;
	float angular;//angular velocity in radians/sec
};



#endif /* MOVEMENT_STEERINGOUTPUT_H_ */
