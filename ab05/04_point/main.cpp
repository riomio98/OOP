
#include <cassert>
#include "line.h"

int main()
{
    Point p;
    assert(p == Point(0, 0));

    Point a(2, 3);
    a += Point(4, 5);
    assert(a == Point(6, 8));

    Line l(Point(1, 2), Point(3, 4));
    l += Point(2, 1);

    assert(l.get_start() == Point(3, 3));
    assert(l.get_end() == Point(5, 5));
}
