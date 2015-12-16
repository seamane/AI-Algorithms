/*
 * KinematicWander.h
 *
 *  Created on: Dec 14, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_KINEMATICWANDER_H_
#define MOVEMENT_KINEMATICWANDER_H_
#include "Kinematic.h"
#include "KinematicType.h"

class KinematicWander : public KinematicType
{
public:
	KinematicWander();
	~KinematicWander();

	KinematicSteeringOutput getSteering();

private:
	//holds the static data for character and target
	Kinematic character;

	//holds the max speed the character can travel
	float maxSpeed;
	float maxRotation;

	float randomBinomial();
};

#endif /* MOVEMENT_KINEMATICWANDER_H_ */
