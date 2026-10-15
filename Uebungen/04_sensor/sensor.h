/*
 * sensor.h
 *
 *  Created on: 12.10.2026
 *      Author: n3034770
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include <string>

class Sensor{
private:
	std::string _name;
	int _mw;
	int _mcnt;
	
public:
	Sensor(std::string name);
	//getter
	std::string GetName() const;
	int GetMesswert() const;
	int GetMessungszahl() const;
	//setter
	void SetMesswert(int mw);
	
};


#endif /* SENSOR_H_ */
