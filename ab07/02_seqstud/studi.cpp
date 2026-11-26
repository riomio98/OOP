/*
 * studi.cpp
 *
 *  Created on: 08.11.2026
 *      Author: n3034770
 */

#include "studi.h"
Studi::Studi()
{}
std::ostream& operator<<(std::ostream& out, const Studi& s)
{
	out << s._matnr << " ";
	out << s._vorname << " ";
	out << s._nachname;

	return out;
}
std::istream& operator>>(std::istream& in, Studi& s)
{
	in >> s._matnr;
	in >> s._vorname;
	in >> s._nachname;

	return in;
}
bool Studi::operator==(const Studi& other) const
{
	return (this->_matnr == other._matnr);
}
bool Studi::operator!=(const Studi& other) const
{
	return (this->_matnr != other._matnr);
}
long Studi::get_matnr()
{
	return _matnr;
}

std::string Studi::get_vorname() {
	return _vorname;
}

std::string Studi::get_nachname() {
	return _nachname;
}

