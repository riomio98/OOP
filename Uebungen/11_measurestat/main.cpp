/*
 * main.cpp
 *
 *  Created on: 29.10.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>
#include <string>
#include "pbma.h"

using namespace std;

void calc_stats(const vector<double>& v, double& min, double& max, double& mean, size_t cnt)
{
	double sum = 0;
	for(size_t i = 0; i < cnt; i++)
	{
		sum += v[i];
		if(v[i] < min)
		{
			min = v[i];
		}
		if(v[i] > max)
		{
			max = v[i];
		}
	}
	mean = sum/ double(cnt);
}

int main(int argc, char* argv[])
{
	args_t args(argc, argv);

	string fname = args.pos(0, "values.txt");
	vector<double> v = read_doubles(fname);
	bool flag = args.flag("v");



	if(v.empty())
	{
		return 1;
	}


	double min = v[0];
	double max = v[0];
	double mean;
	size_t cnt = v.size();

	if(flag)
	{
		for(size_t i = 0; i < cnt; i++)
		{
			cout << v[i] << endl;
		}
	}
	calc_stats(v,min,max,mean,cnt);

	cout << "min: "<< min << endl;
	cout << "max: "<< max << endl;
	cout << "mean: " << mean << endl;
	cout << "count: " << cnt << endl;



	return 0;
}



