/*
 * Kinematic.h
 *
 *  Created on: Dec 11, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_KINEMATIC_H_
#define MOVEMENT_KINEMATIC_H_

#include "../VectorOrPoint.h"
#include "SteeringOutput.h"
#include <math.h>

struct Kinematic
{
	VectorOrPoint position;
	float orientation;//facing direction
	VectorOrPoint velocity;
	float rotation;//process of changing orientation

	void update(struct SteeringOutput steering,float time)
	{

		//update the position and orientation
		position = position.add(velocity.multiply(time).add(steering.linear.multiply(.5*time*time)));
//		position += (velocity * time) + (.5 * steering.linear * time * time);
		orientation += (rotation * time) + (.5 * steering.angular * time * time);

		//and the velocity and rotation
		velocity = velocity.add(steering.linear.multiply(time));
//		velocity += steering.linear * time;
		rotation += steering.angular * time;
	}

	float getNewOrientation(float currentOrientation,VectorOrPoint velocity)
	{
		if(velocity.magnitude() > 0)
		{
			return atan2(velocity.x,velocity.z);
		}
		else
		{
			return currentOrientation;
		}
	}
};

#endif /* MOVEMENT_KINEMATIC_H_ */
