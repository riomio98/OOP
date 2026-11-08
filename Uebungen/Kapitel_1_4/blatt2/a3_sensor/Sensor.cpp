/*
 * Sensor.cpp
 *
 *  Created on: 04.11.2026
 *      Author: n3034770
 */


#include "Sensor.h"

size_t Sensor::_nxt = 1;
int Sensor::_aktive = 0;
int Sensor::_hoechststand = 0;

size_t Sensor::neue_kennung() {
    ++_aktive;
    if (_aktive > _hoechststand)
    {
    	_hoechststand = _aktive;
    }
    return _nxt++;
}
Sensor::Sensor(double mw)
			:_mw(mw), _id(neue_kennung())
{
}

Sensor::~Sensor() {
	_aktive--;
}

Sensor::Sensor(const Sensor &other)
			:_mw(other._mw), _id(neue_kennung())
{
}
Sensor& Sensor::operator =(const Sensor &other)
{
	if(this != &other)
	{
		_mw = other._mw;
	}
	return *this;
}

const size_t Sensor::kennung() const {
	return _id;
}
int Sensor::aktive() {
    return _aktive;
}



void Sensor::messe(double mw) {
	_mw = mw;
}

void tausche_messwerte(Sensor &a, Sensor &b) {

		double tmp = a._mw;
		a._mw = b._mw;
		b._mw = tmp;

}

int Sensor::hoechststand() {
    return _hoechststand;
}

double Sensor::messwert() const {
	return _mw;
}
