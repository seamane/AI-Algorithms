/*
 * Flee.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: ericseaman
 */

#include "Flee.h"

Flee::Flee() {
	// TODO Auto-generated constructor stub

}

Flee::~Flee() {
	// TODO Auto-generated destructor stub
}

SteeringOutput Flee::getSteering()
{
	SteeringOutput steering;

	//get direction to target
	steering.linear = character.position.subtract(target.position);

	//give full acceleration along this direction
	steering.linear.normalize();
	steering.linear = steering.linear.multiply(maxAcceleration);

	//output steering
	steering.angular = 0;
	return steering;
}


