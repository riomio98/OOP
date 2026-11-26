/*
 * main.cpp
 *
 *  Created on: 23.11.2026
 *      Author: n3034770
 */


#include <iostream>
#include <string>
#include "haustier.h"

using namespace std;

int main()
{
	Haustier htier{"?????"};
	Hund waldi{"Waldi", "waldorf"};
	Katze mimmi{"Mimmi"};
	cout << htier.get_name() << " " << htier.gib_laut() << endl; // ????? #
	cout << waldi.get_name() << " " << waldi.gib_laut() << endl; // Waldi wau
	cout << mimmi.get_name() << " " << mimmi.gib_laut() << endl; // Mimmi miau

	Haustier* tier = &waldi;

	cout << tier->get_name() << endl;
	cout << tier->gib_laut() << endl; // gibt "#" aus wen methode nciht virtual

	return 0;
}

