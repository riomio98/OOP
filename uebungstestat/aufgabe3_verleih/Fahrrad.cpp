/*
 * Fahrrad.cpp
 *
 *  Created on: 01.11.2026
 *      Author: n3034770
 */

#include <vector>
#include <string>
#include "fahrrad.h"
#include <stdexcept>
#include <iostream>

size_t Fahrrad::_next_id = 1001;
size_t Fahrrad::_rented_count = 0;

Fahrrad::Fahrrad(std::string model, int km)
			:_model(model), _km(km),_id(_next_id), _last_service(km), _rent(false)
{
	if(_km < 0)
	{
		throw std::runtime_error("negative km");
	}
	_next_id++;
}
Fahrrad::~Fahrrad()
{
	if(_rent)
	{
		_rented_count--;
	}
}
size_t Fahrrad::get_id() const
{
	return _id;
}
const std::string& Fahrrad::get_model() const
{
	return _model;
}
int Fahrrad::get_km() const
{
	return _km;
}
bool Fahrrad::get_rent_status() const
{
	return _rent;
}
bool Fahrrad::set_rent()
{
	if(!_rent)
	{
		_rent = true;
		_rented_count++;
		return true;
	}
	else
	{
		return false;
	}
}
bool Fahrrad::give_back(int km)
{
	if(_rent and km >= 0)
	{
		_km += km;
		_rent = false;
		_rented_count--;
		return true;
	}
	else
	{
		return false;
	}
}

bool Fahrrad::wartung_noetig(int grenze) const
{
	return (_km - _last_service >= grenze)? true: false;
}

bool Fahrrad::wartung()
{
	if(!_rent)
	{
		_last_service = _km;
		return true;
	}
	else
	{
		return false;
	}
}

void umbau(Fahrrad& a, Fahrrad& b)
{
	if(!a._rent and !b._rent and a._id != b._id)
	{
		std::string temp = a._model;
		a._model = b._model;
		b._model = temp;
	}
}
size_t& Fahrrad::get_cnt()
{
	return _rented_count;
}
