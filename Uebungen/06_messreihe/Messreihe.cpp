/*
 * messreihe.cpp
 *
 *  Created on: 21.10.2026
 *      Author: n3034770
 */

#include "Messreihe.h"
#include <stdexcept>

Messreihe::Messreihe(size_t size)
	:_size(size)
{
	_values = new double[_size];
	_values = new double[_size];
	for(size_t i = 0; i < _size; i++)
	{
		_values[i] = 0.0;
	}
}
Messreihe::Messreihe(const Messreihe& other)
	:_size(other._size)
{
	_values = new double[_size];
	for(size_t i = 0; i < _size; i++)
	{
		_values[i] = other._values[i];
	}
}
Messreihe& Messreihe::operator=(const Messreihe& other)
{
	if(this != &other)
	{
		delete [] _values;
		_size = other._size;
		_values = new double[_size];
		for(size_t i = 0; i < _size; i++)
		{
			_values[i] = other._values[i];
		}
	}
	return *this;
}
Messreihe::~Messreihe()
{
	delete [] _values;
}
size_t Messreihe::size() const
{
	return _size;
}
double& Messreihe::at(size_t idx)
{
	if(idx >= _size or _size < 0)
	{
		throw std::runtime_error("index out of range!");
	}
	return _values[idx];
}
const double& Messreihe::at(size_t idx) const
{
	if(idx >= _size or _size < 0)
	{
		throw std::runtime_error("index out of range!");
	}
	return _values[idx];
}



