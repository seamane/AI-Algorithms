/*
 * Evade.h
 *
 *  Created on: Dec 17, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_EVADE_H_
#define MOVEMENT_EVADE_H_

#include "Flee.h"

class Evade : public Flee
{
public:
	Evade();
	~Evade();

	SteeringOutput getSteering();

private:
	Kinematic tempTarget;
	float maxPrediction;
};

#endif /* MOVEMENT_EVADE_H_ */
