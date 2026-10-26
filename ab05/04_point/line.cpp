/*
 * line.cpp
 *
 *  Created on: 26.10.2026
 *      Author: n3034770
 */

#include "line.h"


Point Line::get_start() const
	{
		return bgn;
	}
Point Line::get_end() const
	{
		return end;
	}
Line& Line::operator+=(const Point& other)
{
	bgn += other;
	end += other;

	return *this;
}

bool operator==(const Line& a,const Line& b)
	{
		return (a.get_start() ==  b.get_start()
				&& a.get_end() == b.get_end());
	}
