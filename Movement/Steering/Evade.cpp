/*
 * Evade.cpp
 *
 *  Created on: Dec 17, 2015
 *      Author: ericseaman
 */

#include "Evade.h"

Evade::Evade() {
	// TODO Auto-generated constructor stub

}

Evade::~Evade() {
	// TODO Auto-generated destructor stub
}

/*
	Can make algorithm faster by removing the inheritance to Flee and copying all necessary code into here,
	but to save code duplication, I opted to inherit.
*/
SteeringOutput Evade::getSteering()
{
	//1. Calculate the target to delegate to Seek.getSteering()
	//distance to target
	float distance = tempTarget.position.subtract(character.position).magnitude();
	//get speed
	float speed = character.velocity.magnitude();

	float prediction;
	//check if speed is too small
	if(speed < (distance/maxPrediction))
	{
		prediction = maxPrediction;
	}
	else
	{
		prediction = distance / speed;
	}

	//put target together
	target = tempTarget;
	target.position = target.position.add(target.velocity.multiply(prediction));

	//2. delegate to Seek
	return Flee::getSteering();
}
