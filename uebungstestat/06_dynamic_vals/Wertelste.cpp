/*
 * Wertelste.cpp
 *
 *  Created on: 04.11.2026
 *      Author: n3034770
 */
#include "Werteliste.h"
#include <stdexcept>
#include <string>

Werteliste::Werteliste(std::size_t cap)
						:_cap(cap), _size(0)
{
	if(_cap == 0)
	{
		throw std::runtime_error("invalid capacity: " + std::to_string(_cap));
	}
	_arr = new int[_cap];
}
Werteliste::~Werteliste()
{
	delete [] _arr;
}
Werteliste::Werteliste(const Werteliste& other) //copy
{
	_cap = other._cap;
	_arr = new int[_cap];
	_size = other._size;
	for(size_t i = 0; i < _size; i++)
	{
		_arr[i] = other._arr[i];
	}


}

Werteliste& Werteliste::operator=(const Werteliste& other) // zuweisung
{
	if(this != &other)
	{
		int* tmp_arr = new int[other._cap];
		for(size_t i = 0; i < other._size; i++)
		{
			tmp_arr[i] = other._arr[i];
		}
		delete [] _arr;
		_cap = other._cap;
		_size = other._size;

		_arr = tmp_arr;

	}
	return *this;
}

std::size_t Werteliste::capacity() const
{
	return _cap;
}

std::size_t Werteliste::size() const
{
	return _size;
}
bool Werteliste::empty() const
{
	return (_size == 0);
}

bool Werteliste::full() const
{
	return (_size == _cap);
}
void Werteliste::insert(std::size_t pos, int wert)
{

	if(pos > _size)
	{
		throw std::runtime_error("index out of range");
	}
	if(_size == _cap)
	{
		throw std::runtime_error("full");
	}
	if(pos < _size)
	{
		for(size_t i = _size; i > pos; i--)
		{
			_arr[i] = _arr[i-1];
		}
	}
	_arr[pos] = wert;
	_size++;
}
int Werteliste::erase(std::size_t pos)
{
	int wert;
	if(pos > _size)
	{
		throw std::runtime_error("index out of range");
	}
	if(pos < _size)
	{
		wert = _arr[pos];
		for(size_t i = pos;i < _size-1; i++)
		{
			_arr[i] = _arr[i+1];
		}
	}
	_size--;
	return wert;
}
int& Werteliste::at(std::size_t pos)
{
	if(pos >= _size)
	{
		throw std::runtime_error("index out of range");
	}
	return _arr[pos];
}
const int& Werteliste::at(std::size_t pos) const
{
	if(pos >= _size)
	{
		throw std::runtime_error("index out of range");
	}
	return _arr[pos];
}
void Werteliste::clear()
{
	_size=0;
}


