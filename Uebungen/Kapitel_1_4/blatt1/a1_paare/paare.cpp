/*
 * paare.cpp
 *
 *  Created on: 04.11.2026
 *      Author: n3034770
 */

#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include "pbma.h"
#include <stdexcept>
#include "zahlen.h"

using namespace std;


int main(int argc, const char* argv[])
{
	args_t args(argc, argv);

	string file_name = args.pos(0, "paare.dat");
	vector<int> v = read_ints(file_name);


	if(v.size() % 2 != 0 || v.empty())
	{
		throw std::runtime_error("ungerade Anzahl von Zahlen in " + file_name);
	}

	bool verbose = args.flag("v");
	bool zeit = args.flag("zeit");
	long long sum_k = 0;
	size_t tf = 0;


    for (std::size_t i = 0; i < v.size(); i+=2)
	{
		int a = v[i];
		int b = v[i+1];
		long long k = kgv(a,b);
		if(verbose)
		{
			cout << setw(8) << a << setw(8) << b <<": ";
			cout << "ggT " << ggt(a,b) << ", KgV " << k << endl;
		}
		sum_k += k;

		if(teilerfremd(a,b))
		{
			tf++;
		}
	}
    cout << "Paare: " << v.size()/2 << endl;
    cout << "Teilerfremd: " << tf << endl;
    cout << "Summe KgV: " << sum_k << endl;

	if(zeit)
	{
		vector<int> random_v = create_same_randints(2000000, 1, 1000000);

		Timer timer1;
		for (size_t i = 0; i < random_v.size(); i+= 2) {
			int a = random_v[i];
			int b = random_v[i+1];
			ggt(a,b);
		}
		cout << "ggt dauerte: " << timer1.human_measure() << endl;

		Timer timer2;
		for (size_t i = 0; i < random_v.size(); i+= 2) {
			int a = random_v[i];
			int b = random_v[i+1];
			kgv(a,b);
		}
		cout << "KgV dauerte: " << timer2.human_measure() << endl;
	}


	return 0;
}


