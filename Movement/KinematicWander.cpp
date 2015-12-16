/*
 * KinematicWander.cpp
 *
 *  Created on: Dec 14, 2015
 *      Author: ericseaman
 */

#include "KinematicWander.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

KinematicWander::KinematicWander()
{
	// TODO Auto-generated constructor stub
	srand(time(NULL));
}

KinematicWander::~KinematicWander()
{
	// TODO Auto-generated destructor stub
}

KinematicSteeringOutput KinematicWander::getSteering()
{
	KinematicSteeringOutput steering;
	//get direction to target
	steering.velocity = character.getOrientationAsVector().multiply(maxSpeed);

	//change our orientation randomly
	steering.rotation = randomBinomial() * maxRotation;

	return steering;
}

float KinematicWander::randomBinomial()
{
	//return number between -1 and 1
	return ((float) rand() / (float) RAND_MAX) - ((float) rand() / (float) RAND_MAX);
}
