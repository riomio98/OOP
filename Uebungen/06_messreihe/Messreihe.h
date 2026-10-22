/*
 * messreihe.h
 *
 *  Created on: 21.10.2026
 *      Author: n3034770
 */

#ifndef MESSREIHE_H_
#define MESSREIHE_H_

#include <iostream>

class Messreihe{
private:
	size_t _size;
	double* _values;

public:
	Messreihe(size_t size);
	Messreihe(const Messreihe& other);
	Messreihe& operator=(const Messreihe& other);
	~Messreihe();
	//getter
	size_t size() const;
	//setter
	double& at(size_t idx);
	const double& at(size_t idx) const;
	
};
#endif /* MESSREIHE_H_ */
