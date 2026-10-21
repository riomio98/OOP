/*
 * vec_class.h
 *
 *  Created on: 18.10.2026
 *      Author: n3034770
 */

#ifndef VEC_CLASS_H_
#define VEC_CLASS_H_


#include <stdexcept>

class IntVector{
private:
	int* _arr;
	size_t _len;
	
public:
	//Konstruktor
	IntVector(size_t len);
	IntVector(const IntVector& other); // deepcopy
	IntVector& operator=(const IntVector& other); // Zuweisung
	//Destruktor
	~IntVector();
	//getter
	size_t size() const;
	int& at(size_t idx);
	void out();
};

void klappt();
void copyassign();
void crash();

#endif /* VEC_CLASS_H_ */
