/*
 * main.cpp
 *
 *  Created on: 12.10.2026
 *      Author: n3034770
 */


#include <vector>
#include <iostream>

using namespace std;

void func(vector<int>& v, int& min, int& max, int& sum, int& positive)
{

	
	for(size_t i = 0; i < v.size(); i++)
	{
		if(v[i] < min)
		{
			min = v[i];
		}
		if(v[i] > max)
		{
			max = v[i];
		}
		
		sum += v[i];
		if( v[i] > 0)
		{
			positive++;
		}
	}
}

int main(void) {

	vector<int> p = {4,-2, 8,-5, 1};
	if(p.empty())
	{
		cout << "ERROR" << endl;
		return 0;
	}
	int min = p[0];
	int max = p[0];
	int sum = 0;
	int positive = 0;
	
	func(p, min, max, sum, positive);
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;
	cout << "sum: " << sum << endl;
	cout << "positive: " << positive << endl;

 		
	return 0; 
}


