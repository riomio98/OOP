/*
 * messwerte.cpp
 *
 *  Created on: 01.11.2026
 *      Author: n3034770
 */
#include <stdexcept>
#include <vector>
#include <iostream>
#include "messwerte.h"
#include "alltest.h"
#include "pbma.h"


size_t begrenze(std::vector<int>& v, int min, int max)
{
	if(min > max)
	{
		throw std::runtime_error("invalid range");
	}
	size_t cnt =0;
	for(size_t i = 0; i < v.size(); i++)
	{
		if(v[i] < min)
		{
			v[i] = min;
			cnt++;
		}
		else if(v[i] > max)
		{
			v[i]  = max;
			cnt++;
		}
	}
	return cnt;
}


int& groesster(std::vector<int>& v)
{
	if(v.empty())
	{
		throw std::runtime_error("empty");
	}
	size_t max_val = 0;
	for(size_t i = 0; i < v.size(); i++)
	{
		if(v[i] > v[max_val])
		{
			max_val = i;
		}
	}
	return v[max_val];
}

void kennzahlen(const std::vector<int>& v, double& mean, int& range)
{
	if(v.empty())
	{
		throw std::runtime_error("empty");
	}
	int sum = 0;
	int max_val = v[0];
	int min_val = v[0];
	for(size_t i = 0; i < v.size(); i++)
	{
		sum += v[i];
		if(v[i] > max_val)
		{
			max_val = v[i];
		}
		else if(v[i] < min_val)
		{
			min_val = v[i];
		}
	}
	mean = double(sum) / v.size();
	range = max_val - min_val;

}

size_t entferne_ausreisser(std::vector<int>& v, int limit)
{
	if(limit < 0)
	{
		throw std::runtime_error("invalid limit");
	}

	size_t cnt = 0;
	for(size_t i = 0; i < v.size();)
	{
		if(abs(v[i]) > limit)
		{
			v.erase(v.begin()+i);
			cnt++;
		}
		else
		{
			i++;
		}


	}
	return cnt;
}



