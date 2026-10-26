/*
 * point.h
 *
 *  Created on: 26.10.2026
 *      Author: n3034770
 */

#ifndef POINT_H_
#define POINT_H_
#include <vector>

class Point{
private:
	int _x;
	int _y;
public:
	Point(int x = 0, int y = 0)
		:_x(x), _y(y)
	{
	}
	int get_x() const;
	int Point::get_y() const;
	Point& operator+=(const Point& other);

};

bool operator==(const Point& a, const Point& b);



#endif /* POINT_H_ */
