/*
 * studi.cpp
 *
 *  Created on: 08.11.2026
 *      Author: n3034770
 */

#include "studi.h"

Studi::Studi(long matnr)
:_matnr(matnr)
{
}
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
