/*
 * main.cpp
 *
 *  Created on: 09.11.2026
 *      Author: n3034770
 */

#include <string>
#include <vector>
#include <iostream>
#include <cstddef>
#include <cstring>

using namespace std;




template <typename T>

T max( T* arr, size_t anz)
{

	if(anz == 0)
	{
		return 0;
	}

	T max = arr[0];
	for(size_t i = 0; i < anz; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

template<>

const char* max<const char*>(const char* arr[], size_t anz)
{
	const char* max = arr[0];

	for(size_t i =1; i < anz; i++)
	{
		int char_cmp = strcmp(arr[i], max);
		if(char_cmp > 0)
		{
			max = arr[i];
		}
	}
	return max;
}

int main()
{
	int arr_int[] = {1,2,40,2,4};
	const char* arr_char[] = {"albufeira", "malaga", "frankfurt"};

	cout << max(arr_int, 5) << endl;
	cout << max(arr_char, 3) << endl;

	return 0;
}


