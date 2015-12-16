/*
 * KinematicFlee.h
 *
 *  Created on: Dec 13, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_KINEMATICFLEE_H_
#define MOVEMENT_KINEMATICFLEE_H_

#include "Kinematic.h"
#include "KinematicType.h"

class KinematicFlee : public KinematicType
{
public:
	KinematicFlee(float maxSpeed);
	~KinematicFlee();

	KinematicSteeringOutput getSteering();

	private:
		//holds the static data for character and target
		Kinematic character;
		Kinematic target;

		//holds the max speed the character can travel
		float maxSpeed;
};

#endif /* MOVEMENT_KINEMATICFLEE_H_ */
