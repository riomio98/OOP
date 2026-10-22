/*
 * main.cpp
 *
 *  Created on: 21.10.2026
 *      Author: n3034770
 */

#include "Messreihe.h"

using namespace std;

int main()
{
	Messreihe a(3);
	a.size();
	a.at(1); // rückgabe 0.0 aus values 2. stelle
	
	Messreihe b = a;
	b.at(0) = 99;

	cout << a.at(0) << endl;
	cout << b.at(0) << endl;

	Messreihe c(1);
	c = a;
	c.at(1) = 77;

	cout << c.at(1) << endl;

	const Messreihe d = a;
	cout << d.at(1) << endl;
}

