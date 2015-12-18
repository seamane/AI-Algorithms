/*
 * Arrive.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: ericseaman
 */

#include "Arrive.h"

Arrive::Arrive() {
	// TODO Auto-generated constructor stub

}

Arrive::~Arrive() {
	// TODO Auto-generated destructor stub
}

SteeringOutput Arrive::getSteering()
{
	SteeringOutput steering;
	float targetSpeed = 0.0;

	VectorOrPoint targetVelocity = target.position.subtract(character.position);
	float distance = targetVelocity.magnitude();

	//check if we are there, return no steering
	if(distance < targetRadius)
	{
		steering.linear = VectorOrPoint(0,0,0,0);
		steering.angular = 0.0;
		return steering;
	}

	//if we are outside of slowRadius, then go maxSpeed
	if(distance > slowRadius)
	{
		targetSpeed = maxSpeed;
	}
	else
	{
		targetSpeed = maxSpeed * distance / slowRadius;
	}

	//the target velocity combines speed and direction
	targetVelocity.normalize();
	targetVelocity = targetVelocity.multiply(targetSpeed);

	//acceleration tries to get to the target velocity
	steering.linear = targetVelocity.subtract(character.velocity);
	steering.linear = steering.linear.multiply(1/timeToTarget);

	//check if acceleration is too fast
	if(steering.linear.magnitude() > maxAcceleration)
	{
		steering.linear.normalize();
		steering.linear = steering.linear.multiply(maxAcceleration);
	}

	//output steering
	steering.angular = 0.0;
	return steering;
}
