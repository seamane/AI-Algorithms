/*
 * Character.h
 *
 *  Created on: Dec 14, 2015
 *      Author: ericseaman
 */

#ifndef VECTORORPOINT_H_
#define VECTORORPOINT_H_

#include <string>

using namespace std;

class VectorOrPoint
{
public:
	VectorOrPoint(float x,float y,float z,float w);
	VectorOrPoint();
	~VectorOrPoint();

	string toString();
	VectorOrPoint multiply(float d) const;
	VectorOrPoint subtract(const VectorOrPoint &sub) const;
	VectorOrPoint add(const VectorOrPoint &add);
	inline float magnitude();
	inline float dotProduct(const VectorOrPoint &other) const;
	float angleBetween(VectorOrPoint other);
	VectorOrPoint crossProductWith(const VectorOrPoint &other) const;
	void normalize();
	void homogenize();
	inline bool isVector();
	inline bool isPoint();

	float x,y,z,w;
};

#endif /* VECTORORPOINT_H_ */
