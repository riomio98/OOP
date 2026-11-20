/*
 * vec_class.h
 *
 *  Created on: 18.10.2026
 *      Author: n3034770
 */

#ifndef CommonVector_H_
#define CommonVector_H_

#include <cstddef>
#include <stdexcept>

template <typename T, std::size_t len>
class CommonVector
{
private:
	T* _arr;
	
public:
	//Konstruktor
	CommonVector();
	template <std::size_t N>
	CommonVector(const T (&arr)[N]);
	CommonVector(const CommonVector& other); // deepcopy
	CommonVector& operator=(const CommonVector& other); // Zuweisung
	//Destruktor
	~CommonVector();
	//getter
	size_t size() const;
	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;
	void out() const;
};

#include "CommonVector.cpp"


#endif /* CommonVector_H_ */
