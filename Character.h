/*
 * Character.h
 *
 *  Created on: Dec 14, 2015
 *      Author: ericseaman
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Movement/Kinematics/Kinematic.h"

class Character {
public:
	Character();
	virtual ~Character();

private:
	Kinematic kinematic;
};

#endif /* CHARACTER_H_ */
