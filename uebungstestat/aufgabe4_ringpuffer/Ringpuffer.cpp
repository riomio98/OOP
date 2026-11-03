/*
 * Ringpuffer.cpp
 *
 *  Created on: 02.11.2026
 *      Author: n3034770
 */


#include "Ringpuffer.h"
#include <stdexcept>

Ringpuffer::Ringpuffer(size_t cap)
    : _cap(cap), _size(0), _start(0)
{
	if(_cap <= 0)
	{
		throw std::runtime_error("invalid capacity");
	}
	_arr = new int[_cap]{0};
}
Ringpuffer::~Ringpuffer()
{
	delete [] _arr;
}
Ringpuffer::Ringpuffer(const Ringpuffer& other)
{
	_cap = other._cap;
	_size = other._size;
	_start = other._start;
	_arr = new int[_cap];
	for(size_t i = 0; i < _cap; i++)
	{
		_arr[i] = other._arr[i];
	}
}
Ringpuffer& Ringpuffer::operator=(const Ringpuffer& other)
{
	if(this != &other)
	{

		int* tmp = new int[other._cap];
		for(size_t i = 0; i < other._cap; i++)
		{
			tmp[i] = other._arr[i];
		}
		delete [] _arr;
		_arr = tmp;
		_cap = other._cap;
		_size = other._size;
		_start = other._start;

	}
	return *this;
}

size_t Ringpuffer::capacity() const
{
	return _cap;
}

size_t Ringpuffer::size() const
{
	return _size;
}
bool Ringpuffer::empty() const
{
	if(_size > 0)
	{
		return false;
	}
	return true;
}
bool Ringpuffer::full() const
{
	if(_size < _cap)
	{
		return false;
	}
	return true;
}

Ringpuffer& Ringpuffer::add(int x)
{
    if(_size < _cap)
    {
        _arr[(_start + _size) % _cap] = x;
        _size++;
    }
    else
    {
        _arr[_start] = x;
        _start = (_start + 1) % _cap;
    }
    return *this;
}

int& Ringpuffer::at(size_t idx)
{
	if(idx >= _size)
	{
		throw std::runtime_error("index out of range");
	}
	return _arr[(_start + idx) % _cap];
}
const int& Ringpuffer::at(size_t idx) const
{
	if(idx >= _size)
	{
		throw std::runtime_error("index out of range");
	}
	return _arr[(_start + idx) % _cap];
}
double Ringpuffer::mittel() const
{
	if(this->empty())
	{
		throw std::runtime_error("empty");
	}
	double avg;
	double sum = 0.0;
	for(size_t i = 0; i < _size; i++)
	{
		sum += this->at(i); //_arr[(_start + i) % _cap];
	}
	avg = sum/_size;
	return avg;
}

void Ringpuffer::clear()
{
	_size = 0;
	_start = 0;
}









