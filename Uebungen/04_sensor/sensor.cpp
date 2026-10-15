/*
 * sensor.cpp
 *
 *  Created on: 12.10.2026
 *      Author: n3034770
 */

#include "sensor.h"

Sensor::Sensor(std::string name)
 	:_name(name), _mw(0), _mcnt(0)
{
}
std::string Sensor::GetName() const {
	return _name;
}
int Sensor::GetMesswert() const{
	return _mw;
}
int Sensor::GetMessungszahl() const {
	return _mcnt;
}
void Sensor::SetMesswert(int mw){
	if(mw < 0)
	{
		return;
	}
	this->_mw = mw;
	this->_mcnt ++;
}

