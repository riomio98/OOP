/*
 * main.cpp
 *
 *  Created on: 03.11.2026
 *      Author: n3034770
 */

#include <vector>
#include "werte.h"
#include <iostream>

using namespace std;

int main()
{

	vector<int> v = {4,4,1,4,4};

	int max = v[0];
	int min = v[0];

	cout << verdichte(v) << endl;
	grenzen(v, min, max);
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;

	cout << kleinstes(v) << endl;
	int min_1 = 10;
	cout << min_1 << endl;

	return 0;
}
