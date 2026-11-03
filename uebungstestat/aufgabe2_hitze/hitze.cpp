/*
 * hitze.cpp
 *
 *  Created on: 01.11.2026
 *      Author: n3034770
 */
#include <iostream>
#include <vector>
#include <string>
#include "pbma.h"
#include <iomanip>
#include <fstream>

using namespace std;

int hot_days(const vector<int>& v, int limit)
{
	int hd_cnt = 0;
	for(size_t i = 1; i < v.size() ;i++)
	{
		if(v[i] >= limit)
		{
			hd_cnt++;
		}

	}
	return hd_cnt;
}

size_t longest_period(const vector<int>& v,int limit, size_t& bgn)
{
	size_t  lp = 0;
	size_t actual = 0;
	for(size_t i = 1; i < v.size() ;i++)
	{
		if(v[i] >= limit)
		{
			actual++;
		}
		else
		{
			if(actual > lp)
			{
				lp = actual;
				bgn = i-actual;
			}
			else
			{
				actual = 0;
			}
			actual = 0;
		}
	}
	if(actual > lp)
	{
	    lp = actual;
	    bgn = v.size() - actual;
	}

	return lp;
}

double mean(const vector<int>& v)
{
	double mean;
	int sum = 0;
	for(size_t i = 1; i < v.size(); i++)
	{
		sum += v[i];
	}
	mean = sum/((v.size()-1)*10.0);
	return mean;
}

int frost_n(const vector<int>& v)
{
	int f = 0;
	for(size_t i = 1; i < v.size(); i++)
	{
		if(v[i] < 0)
		{
			f++;
		}
	}

	return f;
}

int main(int argc, const char* argv[])
{

	args_t args(argc, argv);
	string file_name = args.pos(0, "juli.dat");
	vector<int> v = read_ints(file_name);
	if(v.size() <= 1 || v[0] != v.size() - 1)
	{
	    throw runtime_error("invalid data");
	}

	int limit = 300;
	if(args.has_option("grenze"))
	{
		limit = args.int_option("grenze");
	}
	bool details = args.flag("v");
	bool frost = args.flag("frost");
	if(details)
	{
		for(size_t i = 1; i < v.size(); i++)
		{
			double grad = v[i] / 10.0;

			cout << "Tag" << setw(4) << i;
			cout << ":" << setw(6) << fixed << setprecision(1) << grad;
			if(v[i] >= limit)
			{
				cout << " *" << endl;
			}
			else
			{
				cout << endl;
			}
		}
	}
	ofstream outfile;
	ostream* out = &cout;

	if(args.has_option("o"))
	{
	    string out_name = args.option("o");
	    outfile.open(out_name);

	    if(!outfile)
	    {
	        throw runtime_error("cannot write file");
	    }

	    out = &outfile;
	}
	*out << "Tage: " << v[0] << endl;

	int hd = hot_days(v,limit);
	*out << "Hitzetage (>=" << limit/10.0 << "): " << hd << endl;

	size_t bgn_lp = 0;
	size_t lp = longest_period(v,limit, bgn_lp);
	if(lp == 0)
	{
	    *out << "Laengste Hitzeperiode: 0 Tage" << endl;
	}
	else
	{
	    *out << "Laengste Hitzeperiode: "
	         << lp << " Tage ab Tag " << bgn_lp << endl;
	}

	*out << fixed << setprecision(2);
	if(frost)
	{
		*out << "Frosttage: " << frost_n(v) << endl;
	}
	*out << "Mittel: " << mean(v) << endl;







	return 0;
}



