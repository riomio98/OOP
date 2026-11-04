/*
 * main.cpp
 *
 *  Created on: 04.11.2026
 *      Author: n3034770
 */
#include "Werteliste.h"
int main()
{
	Werteliste a(5);
	a.insert(0,1);
	a.insert(1,2);
	a.insert(2,4);
	a.insert(2,3);

	a.erase(0);
	return 0;
}



