/*
 * Kinematic.h
 *
 *  Created on: Dec 11, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_KINEMATIC_H_
#define MOVEMENT_KINEMATIC_H_

#include "../../VectorOrPoint.h"
#include "../Steering/SteeringOutput.h"
#include <math.h>

struct Kinematic
{
	VectorOrPoint position;
	float orientation;//facing direction
	VectorOrPoint velocity;
	float rotation;//process of changing orientation. Angular velocity in radians/sec

	void update(struct SteeringOutput steering,int maxSpeed, float time)
	{

		//update the position and orientation
		position = position.add(velocity.multiply(time).add(steering.linear.multiply(.5*time*time)));
		orientation += (rotation * time) + (.5 * steering.angular * time * time);

		//and the velocity and rotation
		velocity = velocity.add(steering.linear.multiply(time));
		orientation += steering.angular * time;

		//check for speeding and clip
		if (velocity.magnitude() > maxSpeed)
		{
			velocity.normalize();
			velocity = velocity.multiply(maxSpeed);
		}
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

	VectorOrPoint getOrientationAsVector()
	{
		//rotate (0,0,1) around y-axis by orientation degrees

//		 | cos θ    0   sin θ| |x|   | x cos θ + z sin θ|   |x'|
//		 |   0      1       0| |y| = |         y        | = |y'|
//	     |−sin θ    0   cos θ| |z|   |−x sin θ + z cos θ|   |z'|

		return VectorOrPoint(sin(orientation),0,cos(orientation),0);
	}
};

#endif /* MOVEMENT_KINEMATIC_H_ */
