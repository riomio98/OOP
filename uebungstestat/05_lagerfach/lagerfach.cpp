/*
 * lagerfach.cpp
 *
 *  Created on: 04.11.2026
 *      Author: n3034770
 */

#include "lagerfach.h"

size_t Lagerfach::_ges = 0;

Lagerfach::Lagerfach(size_t cap)
	:_cap(cap), _bestand(0)
	{
		if(cap == 0)
		{
			throw std::runtime_error("invalid capacity");
		}
	}
Lagerfach::~Lagerfach()
{
	_ges -= _bestand;
}
//getter
size_t Lagerfach::capacity() const
{
	return _cap;
}
size_t Lagerfach::bestand() const
{
	return _bestand;
}
size_t Lagerfach::gesamtbestand()
{
	return _ges;
}
//setter
bool Lagerfach::einlagern(size_t menge)
{
	if(menge <= _cap - _bestand)
	{
		_bestand+= menge;
		_ges += menge;
		return true;
	}
	else{
		return false;
	}

}
bool Lagerfach::entnehmen(size_t menge)
{
	if(menge <= _bestand)
	{
		_bestand-= menge;
		_ges -= menge;
		return true;
	}
	else{
		return false;
	}

}
void umlagern(Lagerfach& von, Lagerfach& nach,size_t menge)
{
	if(&von != &nach and von._bestand >= menge
	   and nach._cap - nach._bestand  > menge)
	{
		von._bestand -= menge;
		nach._bestand += menge;
	}
}

