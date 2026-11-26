/*
 * main.cpp
 *
 *  Created on: 08.11.2026
 *      Author: n3034770
 */

#include "studi.h"
#include "pbma.h"
#include <iostream>
#include <fstream>
#include "sequence.h"

using namespace std;


void read(ifstream& datei, Sequence<Studi>& seq)
{
	Studi s;
	while(datei >> s) // in studi operator >>
	{
		seq.push_back(s); // in sequence
	}
}

Sequence<Studi> search(Sequence<Studi>& seq, long sm, string svn, string snn)
{

	Sequence<Studi> res;
	for(size_t i = 0; i < seq.size(); i++)
	{
		bool sm_ok = (sm==0);
		bool svn_ok = (svn=="");
		bool snn_ok = (snn=="");


		if(!sm_ok)
		{
			sm_ok = (sm==seq[i].get_matnr());
		}
		if(!svn_ok)
		{
			string name = seq[i].get_vorname();
			svn_ok = (name.find(svn) < name.size());
		}
		if(!snn_ok)
		{
			string name = seq[i].get_nachname();
			snn_ok = (name.find(snn) < name.size());
		}

		if(sm_ok and svn_ok and snn_ok)
		{
			res.push_back(seq[i]);
		}
	}
	return res;
}

void print(Sequence<Studi>& seq)
{
	for(size_t i = 0; i < seq.size(); i++)
	{
		cout << seq[i] << endl;
	}
}



int main(int argc, const char* argv[]) {

	args_t args(argc, argv);
	string fnmae = args.pos(0, "studis.txt");
	long sm = args.long_option("m", 0);
	string svn = args.option("v", "");
	string snn = args.option("n", "");

	ifstream datei{fnmae};
	Sequence<Studi> seq;
	read(datei, seq);
	Sequence<Studi> res = search(seq, sm, svn, snn);
	print(res);


	return 0;
}

