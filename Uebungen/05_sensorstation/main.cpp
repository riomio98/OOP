/*
 * station.cpp
 *
 *  Created on: 12.10.2026
 *      Author: n3034770
 */

#include <vector>
#include "sensor.h"
#include <string.h>
#include <iostream>

using namespace std;

int main ()
{
	vector<Sensor> vec;
	vec.emplace_back("Sensor 1"),
	vec.emplace_back("Sensor 2"),
	vec.emplace_back("Sensor 3"),
	vec.emplace_back("Sensor 4");
	
	for(size_t i = 0; i < vec.size(); i++)
	{
		vec[i].SetMesswert(i);
	}
	int min = vec[0].GetMesswert();
	int max = vec[0].GetMesswert();
	int sum = 0;
	for(size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i].GetName() << endl;
		cout << vec[i].GetMesswert() << endl;
		if(vec[i].GetMesswert() < min)
			min = vec[i].GetMesswert();
		
		if(vec[i].GetMesswert() > max)
			max = vec[i].GetMesswert();
		
		sum += vec[i].GetMesswert();
		
	}
	int avg = sum/vec.size();
	cout << "Average: " << avg << endl;
	
	return 0;
}

