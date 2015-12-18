/*
 * KinematicArrive.h
 *
 *  Created on: Dec 13, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_KINEMATICARRIVE_H_
#define MOVEMENT_KINEMATICARRIVE_H_
#include "Kinematic.h"
#include "KinematicType.h"

class KinematicArrive : public KinematicType
{
public:
	KinematicArrive();
	KinematicArrive(float,float,float);
	~KinematicArrive();

	KinematicSteeringOutput getSteering();

private:
	//holds the static data for character and target
	Kinematic character;
	Kinematic target;

	//holds the max speed the character can travel
	float maxSpeed;
	float radius;
	float timeToTarget;
};

#endif /* MOVEMENT_KINEMATICARRIVE_H_ */
