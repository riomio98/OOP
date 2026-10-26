/*
 * point.cpp
 *
 *  Created on: 26.10.2026
 *      Author: n3034770
 */
#include "point.h"


int Point::get_x() const
	{
		return _x;
	}
int Point::get_y() const
	{
		return _y;
	}
Point& Point::operator+=(const Point& other)
	{
		_x += other._x;
		_y += other._y;
		return *this;
	}


bool operator==(const Point& a, const Point& b)
{
	return (a.get_x() == b.get_x() && a.get_y() == b.get_y());
}




