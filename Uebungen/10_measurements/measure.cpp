/*
 * measure.cpp
 *
 *  Created on: 29.10.2026
 *      Author: n3034770
 */

#include "measure.h"
#include <stdexcept>

Measure::Measure(size_t size)
				:_size(size)
{
	if(_size <= 0)
	{
		throw std::runtime_error("invalid size");
	}
	_data = new double[_size]{0.0};
}
Measure::~Measure()
{
	delete [] _data;
}
size_t Measure::size() const
{
	return _size;
}
double& Measure::at(size_t idx)
{
	if(idx >= _size)
		throw std::runtime_error("invalid index");

	return _data[idx];
}
double Measure::mean() const
{
	double sum = 0;
	double avg = 0;
	for(size_t i = 0; i < _size; i++)
	{
		sum+= _data[i];
	}
	avg = sum/_size;
	return avg;
}
Measure::Measure(const Measure& other)
{
	_size = other._size;
	_data = new double[_size];
	for(size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
}

Measure& Measure::operator=(const Measure& other)
{
	if(this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = new double[_size];
		for(size_t i = 0; i < _size; i++)
		{
			_data[i] = other._data[i];
		}
	}
	return *this;
}

