/*
 * line.h
 *
 *  Created on: 26.10.2026
 *      Author: n3034770
 */

#ifndef LINE_H_
#define LINE_H_

#include "point.h"

class Line{
private:
	Point bgn;
	Point end;
public:
	Line(Point a, Point b)
		:bgn(a), end(b)
	{
	}
	Line()
	{
	}
	Point get_start() const;
	Point get_end() const;
	Line& operator+=(const Point& other);
};

bool operator==(const Line& a,const Line& b);


#endif /* LINE_H_ */
