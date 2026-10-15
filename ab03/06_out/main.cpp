/*
 * main.cpp
 *
 *  Created on: 15.10.2026
 *      Author: n3034770
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Del{
private:
	string arr[3];
public:
	Del(string a = "a", string b = "b", string c = "c")

	{
		arr[0] = a;
		arr[1] = b;
		arr[2] = c;
	}
	friend void out(const Del& del);

};

void out(const Del& del)
{
	cout << del.arr[0] << del.arr[1] << del.arr[2] << endl;
}

int main()
{
	Del d1;
	Del d2("X");
	Del d3("X", "Y");
	Del d4("X", "Y", "Z");
	out(d1); out(d2); out(d3); out(d4);
	cout << endl; // abc Xbc XYc XYZ
	return 0;
}

