/*
 * lagerfach.h
 *
 *  Created on: 04.11.2026
 *      Author: n3034770
 */

#ifndef LAGERFACH_H_
#define LAGERFACH_H_

#include <vector>
#include <stdexcept>


class Lagerfach{
private:
	const size_t _cap;
	size_t _bestand;
	static size_t _ges;
public:
	explicit Lagerfach(size_t cap);
	~Lagerfach();
	Lagerfach();
	size_t capacity() const;
	size_t bestand() const;
	bool einlagern(size_t menge);
	bool entnehmen(size_t menge);
	static size_t gesamtbestand();
	friend void umlagern(Lagerfach& von, Lagerfach& nach,size_t menge);
	Lagerfach(const Lagerfach&) = delete;
	Lagerfach& operator=(const Lagerfach&) = delete;

};

void umlagern(Lagerfach& von, Lagerfach& nach,size_t menge);


#endif /* LAGERFACH_H_ */
