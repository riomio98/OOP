/*
 * main.cpp
 *
 *  Created on: 08.11.2026
 *      Author: n3034770
 */

#include "studi.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream datei{"studis.txt"};
	Studi s;

	while(datei >> s)
	{
		cout << s << endl;
	}




	return 0;
}

