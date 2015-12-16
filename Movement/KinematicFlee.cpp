/*
 * KinematicFlee.cpp
 *
 *  Created on: Dec 13, 2015
 *      Author: ericseaman
 */

#include "KinematicFlee.h"

KinematicFlee::KinematicFlee(float maxSpeed) {
	// TODO Auto-generated constructor stub
	this->maxSpeed = maxSpeed;
}

KinematicFlee::~KinematicFlee() {
	// TODO Auto-generated destructor stub
}

KinematicSteeringOutput KinematicFlee::getSteering()
{
	KinematicSteeringOutput steering;
	//get direction away from target
	steering.velocity = character.position.subtract(target.position);

	//the velocity is along this direction at full speed
	steering.velocity.normalize();
	steering.velocity = steering.velocity.multiply(maxSpeed);

	//face in the direction we want to move
	character.orientation = character.getNewOrientation(character.orientation,steering.velocity);

	//output steering
	steering.rotation = 0;

	return steering;
}
