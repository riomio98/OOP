/*
 * intvector_main.cpp
 *
 *  Created on: 15.10.2026
 *      Author: n3034770
 */

#include <string>
#include <iostream>
#include "pbma.h"
#include "vec_class.h"

using namespace std;


int main(int argc, char** argv)
{
	args_t args(argc, argv);


	if(args.flag("crash"))
	{
		crash();
	}
	else
	{
		klappt();
	}

	copyassign();

	return 0;
}



