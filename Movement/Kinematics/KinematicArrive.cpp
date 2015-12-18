/*
 * KinematicArrive.cpp
 *
 *  Created on: Dec 13, 2015
 *      Author: ericseaman
 */

#include "KinematicArrive.h"

KinematicArrive::KinematicArrive(float radius, float timeToTarget, float maxSpeed) {
	// TODO Auto-generated constructor stub
	this->maxSpeed = maxSpeed;
	this->timeToTarget = timeToTarget;
	this->radius = radius;
}

KinematicArrive::KinematicArrive()
{
	// TODO Auto-generated constructor stub
	radius = 50;
	maxSpeed = 300;
	timeToTarget = 7;
}

KinematicArrive::~KinematicArrive()
{
	// TODO Auto-generated destructor stub
}

KinematicSteeringOutput KinematicArrive::getSteering()
{
	KinematicSteeringOutput steering;
	//get direction to target
	steering.velocity = target.position.subtract(character.position);

	//are we there?
	if(steering.velocity.magnitude() < radius)
	{
		steering.rotation = 0.0;
		steering.velocity = VectorOrPoint(0,0,0,0);
		return steering;
	}

	//we need to move to our target, we'd like to get there in timeToTarget seconds
	steering.velocity = steering.velocity.multiply(1/timeToTarget);

	//if this is too fast, clip it to the maxSpeed
	if(steering.velocity.magnitude() > maxSpeed)
	{
		steering.velocity.normalize();
		steering.velocity = steering.velocity.multiply(maxSpeed);
	}

	//face in the direction we want to move
	character.orientation = character.getNewOrientation(character.orientation,steering.velocity);

	//output steering
	steering.rotation = 0;

	return steering;
}
