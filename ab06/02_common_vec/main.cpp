/*
 * main.cpp
 *
 *  Created on: 09.11.2026
 *      Author: n3034770
 */


#include <iostream>
#include "CommonVector.h"



int main()
{

	CommonVector<int, 10> t;
	for(size_t i = 0;i < t.size() ; i++)
	{
		t[i] = (i+1) * (i+1);
	}
	t.out();
	char text[] = {"Hallo tolle C++ Welt"};
	CommonVector<char, 25> s(text);
	const char* words[] = {"Hallo","tolle","C++","Welt"};
	CommonVector<const char*, 4> u(words);
    u.out();
	s.out();






	return 0;
}

