/*
 * Seek.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: ericseaman
 */

#include "Seek.h"

Seek::Seek() {
	// TODO Auto-generated constructor stub

}

Seek::~Seek() {
	// TODO Auto-generated destructor stub
}

SteeringOutput Seek::getSteering()
{
	SteeringOutput steering;

	//get direction to target
	steering.linear = target.position.subtract(character.position);

	//give full acceleration along this direction
	steering.linear.normalize();
	steering.linear = steering.linear.multiply(maxAcceleration);

	//output steering
	steering.angular = 0;
	return steering;
}
