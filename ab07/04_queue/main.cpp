/*
 * main.cpp
 *
 *  Created on: 26.11.2026
 *      Author: n3034770
 */



#include "queue_temp.h"
#include <vector>
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;



int main(int argc, char **argv) {

	Queue<int> s;

	is_empty_print(s);

	for(size_t i = 1; i < 6; i++)
	{
		s.enter(i*2);
	}
	cout << s << endl;
	cout << "size: " << s.size() << endl;


	cout << "leave: " << s.leave() << endl;
	cout << "leave: " << s.leave() << endl;
	cout << s << endl;
	cout << "size: " << s.size() << endl;

	cout << endl;


	cout << "Kopierkonstruktor test:" << endl;
	Queue<int> a = s;
	a.leave();
	a.enter(99);

	cout << "Original: " << s << endl;
	cout << "Kopie:    " << a << endl;





	return 0;
}

