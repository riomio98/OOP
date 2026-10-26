/*
 * Bruch.cpp
 *
 *  Created on: 25.10.2026
 *      Author: n3034770
 */



#include "Bruch.h"
#include "ggts.h"

Bruch::Bruch(int z, int n)
	        :_z(z), _n(n)
	{
        kuerzen(_z, _n);
	}
int Bruch::zaehler() const
	{
		return _z;
	}
int Bruch::nenner() const
	{
		return _n;
	}


Bruch& Bruch::operator*=(const Bruch& other)
    {
        _z *= other._z;
        _n *= other._n;
        kuerzen(_z, _n);
        return *this;
    }
bool operator==(const Bruch& a, const Bruch& b)
	{

		return (a.zaehler() == b.zaehler() && a.nenner() == b.nenner())? true : false;
	}
bool operator!=(const Bruch& a, const Bruch& b)
	{
		return !(a == b);
	}
Bruch operator*(Bruch a,const Bruch& b)
{
    return a *= b;
}

void kuerzen(int& z, int& n)
{
    int ggt = ggt2(z, n);
    z /= ggt;
    n /= ggt;
}

