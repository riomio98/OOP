/*
 * main.cpp
 *
 *  Created on: 12.10.2026
 *      Author: n3034770
 */
#include "sensor.h"
#include <iostream>
#include <vector>
#include <string>
#include "pbma.h"
#include <iomanip>

using namespace std;

int main()
{
	
	Sensor s("Senor1");
	cout << "Name:" << setw(20) << s.GetName() << endl;
	
	
	vector<int> v = create_randints(5, 0, 10000);
	
	for(size_t i = 0; i < v.size(); i ++)
	{
		s.SetMesswert(v[i]);
		cout << "aktueller Messwert: " << setw(4) << s.GetMesswert() << endl;
		
	}
	cout << "Anzahl der Messungen: "<< setw(2) << s.GetMessungszahl() << endl;
	
	
	
	return 0;
}