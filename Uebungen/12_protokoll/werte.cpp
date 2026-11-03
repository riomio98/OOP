/*
 * werte.cpp
 *
 *  Created on: 03.11.2026
 *      Author: n3034770
 */

#include<vector>
#include"werte.h"
#include <stdexcept>


int verdichte(std::vector<int>& v)
{
	int cnt = 0;

	for(size_t i = 1; i < v.size();)
	{
		if(v[i-1] == v[i])
		{
			v.erase(v.begin() +i-1); // erase benötigt anfang
			cnt++;
		}
		else{
			i++;
		}
	}
	return cnt;
}

int& kleinstes(std::vector<int>& v)
{
	if(v.empty())
	{
		throw std::runtime_error("empty");
	}
	int min = 0;
	size_t n = v.size();
	for(size_t i = 1; i < n; i++)
	{
		if(v[i] < min)
		{
			min = i;
		}
	}

	return v[min];
}

void grenzen(const std::vector<int>& v,int
			&min,int &max)
{
	size_t n = v.size();
	for(size_t i = 1; i < n; i++)
	{
		if(v[i] < min)
		{
			min = v[i];
		}
		else if(v[i] > max)
		{
			max = v[i];
		}
	}
}
