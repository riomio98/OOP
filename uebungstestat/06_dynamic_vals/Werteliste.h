/*
 * Werteliste.h
 *
 *  Created on: 04.11.2026
 *      Author: n3034770
 */

#ifndef WERTELISTE_H_
#define WERTELISTE_H_

#include <cstddef>



class Werteliste{
private:
	int* _arr;
	std::size_t _cap;
	std::size_t _size;
public:
	explicit Werteliste(std::size_t cap);
	~Werteliste();
	Werteliste(const Werteliste& other);
	Werteliste& operator=(const Werteliste& other);
	std::size_t capacity() const;
	std::size_t size() const;
	bool full() const;
	bool empty() const;
	void insert(std::size_t pos, int wert);
	int erase(std::size_t pos);
	int& at(std::size_t pos);
	const int& at(std::size_t pos) const;
	void clear();


};



#endif /* WERTELISTE_H_ */
