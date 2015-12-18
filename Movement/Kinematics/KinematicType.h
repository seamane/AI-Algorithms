/*
 * KinematicType.h
 *
 *  Created on: Dec 14, 2015
 *      Author: ericseaman
 */

#ifndef MOVEMENT_KINEMATICTYPE_H_
#define MOVEMENT_KINEMATICTYPE_H_

#include "KinematicSteeringOutput.h"

class KinematicType {
public:
	KinematicType(){}
	virtual ~KinematicType(){}

	virtual KinematicSteeringOutput getSteering() = 0;
};

#endif /* MOVEMENT_KINEMATICTYPE_H_ */
