/*
 * main.cpp
 *
 *  Created on: 09.11.2026
 *      Author: n3034770
 */

#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

template <typename T>

int find(const T* arr, size_t n, const T& gesucht)
{
	for(size_t i = 0; i < n; i++)
	{
		if(gesucht == arr[i])
		{
			return i;
		}
	}
	return -1;
}



int main()
{

	int a[]{4, 7, 2, 7};
	double b[]{1.5, 2.5, 3.5};
	string c[]{"Berlin", "Mannheim", "Frankfurt"};

	cout << find(a, 4, 7) << endl;                    // 1
	cout << find(b, 3, 3.5) << endl;                  // 2
	cout << find(c, 3, string("Frankfurt")) << endl; // 2
	cout << find(a, 4, 99) << endl;                   // -1

	return 0;
}


