/*
 * Pursue.cpp
 *
 *  Created on: Dec 17, 2015
 *      Author: ericseaman
 */

#include "Pursue.h"

Pursue::Pursue() : Seek(){
	// TODO Auto-generated constructor stub

}

Pursue::~Pursue() {
	// TODO Auto-generated destructor stub
}

/*
	Can make algorithm faster by removing the inheritance to Seek and copying all necessary code into here,
	but to save code duplication, I opted to inherit. Also, if character can move faster than target,
	there is a chance that it will overshoot the target and oscillate around the target. To avoid this,
	we can replace the delegated call to seek with a call to arrive.
*/
SteeringOutput Pursue::getSteering()
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
	return Seek::getSteering();
}
