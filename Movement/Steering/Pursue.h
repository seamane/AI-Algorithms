/*
 * Pursue.h
 *
 *  Created on: Dec 17, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_PURSUE_H_
#define MOVEMENT_PURSUE_H_

#include "Seek.h"

class Pursue : public Seek
{
public:
	Pursue();
	~Pursue();

	SteeringOutput getSteering();

private:
	Kinematic tempTarget;
	float maxPrediction;
};

#endif /* MOVEMENT_PURSUE_H_ */
