/*
 * VectorOrPoint.cpp
 *
 *  Created on: Dec 11, 2015
 *      Author: ericseaman
 */

#include "VectorOrPoint.h"
#include <sstream>
#include <math.h>


VectorOrPoint::VectorOrPoint(float x,float y,float z,float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

VectorOrPoint::VectorOrPoint() {
	// TODO Auto-generated constructor stub
	x = -1;
	y = -1;
	z = -1;
	w = 1;
}

VectorOrPoint::~VectorOrPoint() {
	// TODO Auto-generated destructor stub
}

inline bool VectorOrPoint::isPoint()
{
	return w != 0.0f;
}

inline bool VectorOrPoint::isVector()
{
	return w == 0.0f;
}

void VectorOrPoint::homogenize()
{
  if(isPoint())
  {
    x /= w;
    y /= w;
    z /= w;
    w = 1.0;
  }
}

void VectorOrPoint::normalize()
{
  if(isVector())
  {
    float denom = (float)sqrt(x*x + y*y + z*z);
    x /= denom;
    y /= denom;
    z /= denom;
  }
}

VectorOrPoint VectorOrPoint::crossProductWith(const VectorOrPoint &other) const
{
  VectorOrPoint result(0,0,0,0);
  result.x = y*other.z - z*other.y;
  result.y = -(x*other.z - z*other.x);
  result.z = x*other.y - y*other.x;
  return result;
}

float VectorOrPoint::angleBetween(VectorOrPoint other)
{
  float result = -1;
  if(isVector())
  {
    result = dotProduct(other);
    result /= (magnitude()*other.magnitude());
    result = (float) acos(result);
  }
  return result;
}

inline float VectorOrPoint::dotProduct(const VectorOrPoint &other) const
{
  return x*other.x + y*other.y + z*other.z;
}

inline float VectorOrPoint::magnitude()
{
  return sqrt(x*x + y*y + z*z);
}

VectorOrPoint VectorOrPoint::add(const VectorOrPoint &add)
{
	return VectorOrPoint(x+add.x,y+add.y,z+add.z,w+add.w);
}

VectorOrPoint VectorOrPoint::subtract(const VectorOrPoint &sub) const
{
	return VectorOrPoint(x-sub.x,y-sub.y,z-sub.z,w-sub.w);
}

VectorOrPoint VectorOrPoint::multiply(float d) const
{
  	return VectorOrPoint(x*d,y*d,z*d,w*d);
}

string VectorOrPoint::toString()
{
	stringstream ss;
	ss << "(" << x << "," << y << "," << z << "," << w << ")";
	return ss.str();
}

//VectorOrPoint VectorOrPoint::operator+(const VectorOrPoint& add)
//{
//	return VectorOrPoint(x+add.x,y+add.y,z+add.z,w+add.w);
//}
//
//VectorOrPoint VectorOrPoint::operator+=(const VectorOrPoint& add)
//{
//	return VectorOrPoint(x+add.x,y+add.y,z+add.z,w+add.w);
//}
//
//VectorOrPoint VectorOrPoint::operator-(const VectorOrPoint& sub)
//{
//	return VectorOrPoint(x-sub.x,y-sub.y,z-sub.z,w-sub.w);
//}
//
//VectorOrPoint VectorOrPoint::operator*(const float mult)
//{
//	return VectorOrPoint(x*mult,y*mult,z*mult,w*mult);
//}

//VectorOrPoint VectorOrPoint::operator*(const VectorOrPoint& m,const float mult)
//{
//	return VectorOrPoint(m.x*mult,m.y*mult,m.z*mult,m.w*mult);
//}
