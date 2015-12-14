/*
 * VectorOrPoint.h
 *
 *  Created on: Dec 11, 2015
 *      Author: ericseaman
 */

#ifndef VECTORORPOINT_H_
#define VECTORORPOINT_H_
#include <math.h>
#include <string>

using namespace std;

class VectorOrPoint {
public:
	VectorOrPoint(float,float,float,float);
	VectorOrPoint();
	~VectorOrPoint();

//	VectorOrPoint operator+(const VectorOrPoint& add);
//	VectorOrPoint operator+=(const VectorOrPoint& add);
//	VectorOrPoint operator-(const VectorOrPoint& sub);
//	VectorOrPoint operator*(const float mult);

	bool isPoint();
	bool isVector();
	void homogenize();
	void normalize();
	VectorOrPoint crossProductWith(const VectorOrPoint&) const;
	float angleBetween(VectorOrPoint);
	float dotProduct(const VectorOrPoint&) const;
	float magnitude();
	string toString();
	VectorOrPoint add(const VectorOrPoint&);
	VectorOrPoint subtract(const VectorOrPoint &sub) const;
	VectorOrPoint multiply(float d) const;

	float x,y,z,w;
};



#endif /* VECTORORPOINT_H_ */

