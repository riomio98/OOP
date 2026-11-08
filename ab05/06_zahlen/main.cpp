/*
 * main.cpp
 *
 *  Created on: 08.11.2026
 *      Author: n3034770
 */


#include <vector>
#include <string>
#include "pbma.h"

using namespace std;

long max(vector<long>& v)
{
	long max = v[0];
	for(size_t i = 0; i < v.size(); i++)
	{
		if(v[i] > max)
		{
			max = v[i];
		}
	}
	return max;
}

long anz(vector<long>& v)
{

	long anz = v.size();

	return anz;
}

int main(int argc, const char* argv[])
{
	args_t args(argc, argv);

	string fname = args.pos(0, "zahlen.dat");

	vector<long> v = read_longs(fname);
	cout << "Max: " << max(v) << endl;
	cout << "Anz: " << anz(v) << endl;


	return 0;
}
