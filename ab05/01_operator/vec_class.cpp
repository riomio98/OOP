/*
 * vec_class.cpp
 *
 *  Created on: 18.10.2026
 *      Author: n3034770
 */
#include "vec_class.h"
#include "pbma.h"

IntVector::IntVector(size_t len)
	:_len(len)
{
	_arr = new int[_len];
}
IntVector::IntVector(const IntVector& other) // Kopierkonstruktor - deepcopy
	: _len(other._len)
{
	_arr = new int[_len];
	for(size_t i = 0; i < _len; i++)
	{
		_arr[i] = other._arr[i];
	}
}
IntVector& IntVector::operator=(const IntVector& other) // Zuweisung
{
	if(this != &other)
	{
		delete [] _arr;
		_len = other._len;
		_arr = new int[_len];
		for(size_t i = 0; i < _len; i++)
		{
			_arr[i] = other._arr[i];
		}
	}
	return *this;
}
IntVector::~IntVector()
{
	delete [] _arr;
}

size_t IntVector::size() const
{
	return _len;
}

int& IntVector::at(size_t idx)
{
	if(idx >= _len)
	{
		throw std::runtime_error("index out of range");
	}
	return _arr[idx];
}
int& IntVector::operator[](size_t idx)
{
	if(idx >= _len)
	{
		throw std::runtime_error("index out of range");
	}
	return _arr[idx];

}

void IntVector::out()
{
	for(size_t i = 0; i < _len ; i++)
	{
		std::cout << "arr[" << i << "] = " << _arr[i] << std::endl;
	}
}

void klappt()
{
	size_t len = 17;
	IntVector v(len);
	for(size_t i = 0; i < v.size(); i++)
	{
		//v.at(i) = i;
		v[i] = i;
	}
	std::cout << "Laenge: " << v.size() << std::endl;
	v.out();
	std::cout << std::endl;
	for(size_t i = 0; i < v.size(); i++)
	{
		if(i%2==0)
		{
			//v.at(i) = i;
			v[i] += 42;
		}
	}
	std::cout << "Laenge: " << v.size() << std::endl;
	v.out();
	std::cout << std::endl;
}

void copyassign()
{
	IntVector v1(17); //Normaler Konst
	for(size_t i = 0; i < v1.size(); i++)
	{
		//v.at(i) = i;
	    v1[i] = i;
	}
	IntVector v2 = v1; //Kopier Konst
	IntVector v3(10); // normaler Konst
	v3 = v2; // Zuweisung

	std::cout << "v1 Laenge: " << v1.size() << std::endl;
	std::cout << "v2 Laenge: " << v2.size() << std::endl;
	std::cout << "v3 Laenge: " << v3.size() << std::endl;

	v1.out(); // erwartung 17
	v2.out(); // erwartung 17
	v3.out(); // erwartung 17
	
}

void crash()
{
	size_t len = 17;
	IntVector v(len);
	v.at(42);

}
