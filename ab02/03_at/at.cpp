/*
 * at_main.cpp
 *
 *  Created on: 01.10.2026
 *      Author: n3034770
 */

#include <iostream>
#include <stdexcept>
#include "at.h"


using namespace std;

int& at(int* vec, int len, int i)
{
	if(i >= len)
	{
		throw runtime_error("index overflow");

	}
	else
	{
		return vec[i];
	}


}
