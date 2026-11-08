/*
 * Sensor.h
 *
 *  Created on: 04.11.2026
 *      Author: n3034770
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include <cstddef>

class Sensor{
private:
	double _mw;
	const size_t _id;
	static size_t _nxt;
    static int _aktive;
    static int _hoechststand;

	static size_t neue_kennung();
public:
	explicit Sensor(double mw = 0.0);
	~Sensor();
	Sensor(const Sensor& other);
	Sensor& operator=(const Sensor& other);
	const size_t kennung() const;
	double messwert() const;
	void messe(double mw);
	friend void tausche_messwerte(Sensor& a, Sensor& b);
	static int hoechststand();
	static int aktive();

};

void tausche_messwerte(Sensor& a, Sensor& b);




#endif /* SENSOR_H_ */
