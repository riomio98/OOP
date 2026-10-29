/*
 * main.cpp
 *
 *  Created on: 29.10.2026
 *      Author: n3034770
 */

#include <vector>
#include "measure.h"
#include <iostream>

using namespace std;

int main()
{


	Measure a(3);

	a.at(0) = 10.5;
	a.at(1) = 20.5;
	a.at(2) = 30.5;

	cout << a.mean() << endl;

	Measure b(a);
	b.at(0) = 100.0;

	cout << a.at(0) << endl;
	cout << b.at(0) << endl;

	Measure c(2);

	c=a;


 return 0;
}


