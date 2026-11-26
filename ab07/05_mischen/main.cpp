/*
 * main.cpp
 *
 *  Created on: 26.11.2026
 *      Author: n3034770
 */
#include "queue_temp.h"
#include "pbma.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>


using namespace std;

int main(int argc, char **argv) {

	args_t args(argc, argv);

	string fname = args.pos(0, "gemischt.txt");
	vector<string> lines = read_lines(fname);

	vector<Queue<char>> zeilen(4);
	for(size_t i = 1; i < lines.size(); i++)
	{
		for(char c : lines[i])
		{
			zeilen[i-1].enter(c);
		}
	}
	for(char c : lines[0])
	{
		int zahl = c - '0'; // bsp.: 51-48 = zeile 3 ASCII
		if(zahl == 5)
		{
			cout << '\n';
		}
		else{
			cout << zeilen[zahl-1].leave();
		}
	}
	return 0;
}



