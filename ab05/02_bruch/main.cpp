/*
 * main.cpp
 *
 *  Created on: 22.10.2026
 *      Author: n3034770
 */
#include "ggts.h"
#include <iostream>
#include "Bruch.h"


using namespace std;



int main()
{
	Bruch a(1,4);
	Bruch b(2,4);
    cout << (b == a) << endl;
    cout << (b != a) << endl;
    cout << "a: "<< a.zaehler() << "/" << a.nenner() << endl;
    cout << "b: "<< b.zaehler() << "/" << b.nenner() << endl;

    Bruch c = 2 * Bruch(15, 4);
    cout << "c: "<< c.zaehler() << "/" << c.nenner() << endl;

    Bruch d(10,20);
    Bruch e(5,10);
    cout << "d: "<< d.zaehler() << "/" << d.nenner() << endl;
    cout << "e: "<< d.zaehler() << "/" << d.nenner() << endl;
    d *= e;
    cout << "d: "<< d.zaehler() << "/" << d.nenner() << endl;

	return 0;
}


