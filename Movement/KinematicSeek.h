/*
 * KinematicSeek.h
 *
 *  Created on: Dec 11, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_KINEMATICSEEK_H_
#define MOVEMENT_KINEMATICSEEK_H_
#include "Kinematic.h"
#include "KinematicSteeringOutput.h"

class KinematicSeek {
public:
	KinematicSeek(float maxSpeed);
	~KinematicSeek();

	KinematicSteeringOutput getSteering();

private:
	//holds the static data for character and target
	Kinematic character;
	Kinematic target;

	//holds the max speed the character can travel
	float maxSpeed;
};

#endif /* MOVEMENT_KINEMATICSEEK_H_ */
