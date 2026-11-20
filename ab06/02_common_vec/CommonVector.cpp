/*
 * vec_class.cpp
 *
 *  Created on: 18.10.2026
 *      Author: n3034770
 */

#include "CommonVector.h"

#ifndef CommonVector_CPP_
#define CommonVector_CPP_
#include <iostream>
#include <stdexcept>

template <typename T, size_t len>
CommonVector<T, len>::CommonVector()
{
	_arr = new T[len]{};
}
template <typename T, size_t len>
template <size_t N>
CommonVector<T, len>::CommonVector(const T (&arr)[N])
{
	_arr = new T[len]{};
	if(N > len)
	{
		throw std::runtime_error("size > cap");
	}
	for(size_t i = 0; i < N; i++)
	{
		_arr[i] = arr[i];
	}


}
template <typename T, size_t len>
CommonVector<T, len>::CommonVector(const CommonVector& other) // deepcopy
{
	_arr = new T[len];
	for(size_t i = 0; i < len; i++)
	{
		_arr[i] = other._arr[i];
	}
}
template <typename T, size_t len>
CommonVector<T, len>& CommonVector<T, len>::operator=(const CommonVector& other) // Zuweisung
{
	if(this != &other)
	{
		for(size_t i = 0; i < len; i++)
		{
			_arr[i] = other._arr[i];
		}
	}
	return *this;
}
template <typename T, size_t len>
CommonVector<T, len>::~CommonVector()
{
	delete [] _arr;
}

template <typename T, size_t len>
size_t CommonVector<T, len>::size() const
{
	return len;
}


template <typename T, size_t len>
T& CommonVector<T, len>::operator[](size_t idx)
{
	if(idx >= len)
	{
		throw std::runtime_error("index out of range");
	}
	return _arr[idx];
}

template <typename T, size_t len>
const T& CommonVector<T, len>::operator[](size_t idx) const
{
	if(idx >= len)
	{
		throw std::runtime_error("index out of range");
	}
	return _arr[idx];
}



template<typename T, size_t len>
void CommonVector<T, len>::out() const {
	std::cout << "[ ";
	for (std::size_t i = 0; i < len; i += 1) {
		if (i > 0 && i % 10 == 0) {
			std::cout << std::endl << " ";
		}
		std::cout << _arr[i] << " ";
	}
	std::cout << "]";
}

#endif
