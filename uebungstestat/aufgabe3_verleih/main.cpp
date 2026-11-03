/*
 * main.cpp
 *
 *  Created on: 02.11.2026
 *      Author: n3034770
 */

#include <vector>
#include <string>
#include <iostream>
#include "fahrrad.h"

using namespace std;

int main()
{

	Fahrrad a("rio");
	cout << a.get_model() << endl;
	cout << a.get_km() << endl;
	cout << a.get_id() << endl;

	cout << a.get_rent_status() << endl;
	cout << a.set_rent() << endl;
	cout << a.get_rent_status() << endl;
	cout << a.give_back(540) << endl;
	cout << a.wartung_noetig()<< endl;
	cout << a.wartung() <<endl;
	Fahrrad b("ramjam", 300);
	cout << b.get_model() << endl;
	cout << b.get_km() << endl;
	cout << b.get_id() << endl;


	umbau(a,b);
	cout << a.get_model() << endl;
	cout << b.get_model() << endl;








	return 0;
}

