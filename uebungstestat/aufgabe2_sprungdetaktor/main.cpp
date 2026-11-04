/*
 * main.cpp
 *
 *  Created on: 03.11.2026
 *      Author: n3034770
 */
#include <iostream>
#include <vector>
#include <string>
#include "pbma.h"
#include <iomanip>

using namespace std;

size_t sprung_cnt(vector<int>& v,int schwelle, size_t n)
{
	size_t cnt = 0;
	for(size_t i = 2; i <= n; i++)
	{
		int diff = abs(v[i] - v[i-1]);
		if(diff >= schwelle)
		{
			cnt++;
		}
	}
	return cnt;
}

int max_sprung(vector<int>& v, size_t n)
{
	size_t idx = 2;
	int max = abs(v[2] - v[1]);

	for(size_t i = 3; i <= n; i++)
	{
		int diff = abs(v[i] - v[i-1]);
		if(diff > max)
		{
			max = diff;
			idx = i;
		}
	}
	return idx;
}

double arith_mittel(vector<int>& v, size_t n)
{
	double mean;
	double sum = 0;
	for(size_t i = 1; i <= n; i++)
	{
		sum += v[i];
	}

	mean = sum /n;

	return mean;
}

void info(vector<int>& v, size_t n, int schwelle)
{

	cout << "Wert 1: " << setw(4) << v[1] << endl;
	for(size_t i = 2; i <= n; i++)
	{

		if(abs(v[i] -v[i-1]) >= schwelle)
		{
			cout << "Wert " << i << ": " << setw(4) << v[i] << "*" << endl;
		}
		else
		{
			cout << "Wert " << i << ": " << setw(4) << v[i] << endl;
		}
	}
}

int main(int argc, const char* argv[])
{

	args_t args(argc, argv);

	string file_name = args.pos(0, "messung.dat");
	bool details = args.flag("v");

	vector<int> v = read_ints(file_name);

	if(v.size() < 3 || int(v.size()) - 1 != v[0])
	{
		throw runtime_error("suspicious array size");
	}

	size_t n = v[0];

	for(size_t i = 2; i <= n; i++)
	{
		if(-10000 > v[i] || v[i] > 10000)
		{
			throw runtime_error("value out of range [-10000, 10000]");
		}
	}

	int schwelle;
	if(args.has_option("schwelle"))
	{
		schwelle = args.int_option("schwelle");
	}
	else
	{
		schwelle = 6;
	}
	if(schwelle <= 0)
	{

		throw runtime_error("invalid value!");
	}


	cout << "Werte: " << n << endl;
	cout << "Sprung: " << sprung_cnt(v,schwelle,n) << " über Schwelle: " << schwelle << endl;
	size_t max_idx = max_sprung(v,n);
	int max = abs(v[max_idx] - v[max_idx-1]);
	cout << "Max: " << max << " bei Wert "<< max_idx <<  endl;
	cout << "Mittel: "<< fixed << setprecision(2) << arith_mittel(v,n) << endl;
	if(details)
	{
		info(v,n, schwelle);
	}




	return 0;
}



