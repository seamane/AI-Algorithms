/*
 * main.cpp
 *
 *  Created on: Dec 11, 2015
 *      Author: ericseaman
 */
#include <iostream>
#include "VectorOrPoint.h"

using namespace std;

int main()
{
	VectorOrPoint v(1,1,1,1);
	VectorOrPoint t(1,1,1,1);

	VectorOrPoint temp = v.add(t);// + t;
	cout << temp.toString() << endl;

	temp = temp.multiply(5);
	cout << temp.toString() << endl;
	temp = temp.multiply(2);
	cout << temp.toString() << endl;

	return 0;

}



