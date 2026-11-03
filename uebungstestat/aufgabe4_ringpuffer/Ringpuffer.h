/*
 * Ringpuffer.h
 *
 *  Created on: 02.11.2026
 *      Author: n3034770
 */

#ifndef RINGPUFFER_H_
#define RINGPUFFER_H_

#include <vector>

class Ringpuffer
{
private:
	int* _arr;
	size_t _cap;
	size_t _size;
	size_t _start;
public:
	explicit Ringpuffer(size_t cap);
	~Ringpuffer();
	Ringpuffer(const Ringpuffer& other);
	Ringpuffer& operator=(const Ringpuffer& other);
	size_t capacity() const;
	size_t size() const;
	bool empty() const;
	bool full() const;
	Ringpuffer& add(int x);
	int& at(size_t idx);
	const int& at(size_t idx) const;
	double mittel() const;
	void clear();
};



#endif /* RINGPUFFER_H_ */
