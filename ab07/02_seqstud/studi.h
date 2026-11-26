/*
 * studi.h
 *
 *  Created on: 08.11.2026
 *      Author: n3034770
 */

#ifndef STUDI_H_
#define STUDI_H_

#include<iostream>
#include<string>

class Studi{
private:
	long _matnr;
	std::string _vorname;
	std::string _nachname;
public:
	Studi();
	long get_matnr();
	std::string get_vorname();
	std::string get_nachname();
	friend std::ostream& operator<<(std::ostream& out, const Studi& s);
	friend std::istream& operator>>(std::istream& in, Studi& s);
	bool operator==(const Studi& other) const;
	bool operator!=(const Studi& other) const;
	size_t size();


};

std::ostream& operator<<(std::ostream& out, const Studi& s);
std::istream& operator>>(std::istream& in, Studi& s);


#endif /* STUDI_H_ */
