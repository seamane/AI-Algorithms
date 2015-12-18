/*
 * Align.cpp
 *
 *  Created on: Dec 16, 2015
 *      Author: ericseaman
 */

#include "Align.h"
#include <math.h>//M_PI
#include <cmath>//abs

Align::Align() {
	// TODO Auto-generated constructor stub

}

Align::~Align() {
	// TODO Auto-generated destructor stub
}

SteeringOutput Align::getSteering()
{
	SteeringOutput steering;

	float rotation = target.orientation - character.orientation;
	float rotationDirection = mapToRange(rotation);
	float rotationSize = abs(rotationDirection);

	//check if we are there, return no steering
	if(rotationSize < targetRadius)
	{
//		return NULL;
	}

	float targetRotation;

	//if we are outside slowRadius, use maxRotation
	if(rotationSize > slowRadius)
	{
		targetRotation = maxRotation;
	}
	else
	{
		targetRotation = maxRotation * rotationSize / slowRadius;
	}

	//the final target rotation combines speed and direction
	targetRotation *= rotation / rotationSize;

	//acceleration tries to get to target rotation
	steering.angular = targetRotation - character.rotation;
	steering.angular /= timeToTarget;

	//check if acceleration is too great
	float angularAcceleration = abs(steering.angular);
	if(angularAcceleration > maxAngularAcceleration)
	{
		steering.angular /= angularAcceleration;
		steering.angular *= maxAngularAcceleration;
	}

	//output steering
	steering.linear = VectorOrPoint(0,0,0,0);
	return steering;
}

float Align::mapToRange(float rotation)
{
//	rotation %= (float)M_PI;
	if(rotation > M_PI)
	{
		rotation -= (2*M_PI);
	}

	return rotation;
}
