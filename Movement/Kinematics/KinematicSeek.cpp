/*
 * KinematicSeek.cpp
 *
 *  Created on: Dec 11, 2015
 *      Author: ericseaman
 */

#include "KinematicSeek.h"

KinematicSeek::KinematicSeek(float maxSpeed) {
	// TODO Auto-generated constructor stub
	this->maxSpeed = maxSpeed;
}

KinematicSeek::~KinematicSeek() {
	// TODO Auto-generated destructor stub
}

KinematicSteeringOutput KinematicSeek::getSteering()
{
	KinematicSteeringOutput steering;
	//get direction to target
	steering.velocity = target.position.subtract(character.position);

	//the velocity is along this direction at full speed
	steering.velocity.normalize();
	steering.velocity = steering.velocity.multiply(maxSpeed);

	//face in the direction we want to move
	character.orientation = character.getNewOrientation(character.orientation,steering.velocity);

	//output steering
	steering.rotation = 0;

	return steering;
}
