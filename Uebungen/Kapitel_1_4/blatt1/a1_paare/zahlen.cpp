/*
 * zahlen.cpp
 *
 *  Created on: 04.11.2026
 *      Author: n3034770
 */


#include "zahlen.h"
#include <cstdlib>


int ggt(int a, int b) {
    if (b == 0) {
        return a;
    }
    return ggt(b, a % b);
}

long long kgv(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return static_cast<long long>(std::abs(a)) / ggt(a, b) * std::abs(b);
}

bool teilerfremd(int a, int b)
{
	return (ggt(a,b) == 1);
}
