/*
 * masure.h
 *
 *  Created on: 29.10.2026
 *      Author: n3034770
 */

#ifndef MEASURE_H_
#define MEASURE_H_
#include <vector>

class Measure{
private:
	size_t _size;
	double* _data;
public:
	Measure(size_t size);
	~Measure();
	//getter
	size_t size() const;
	double at(size_t idx) const;
	//Setter
	double& at(size_t idx);
	double mean() const;
	//rule of three
	Measure(const Measure& other);
	Measure& operator=(const Measure& other);
};



#endif /* MEASURE_H_ */
