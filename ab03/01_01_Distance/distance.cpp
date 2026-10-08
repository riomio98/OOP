/*
 * distance.cpp
 *
 *  Created on: 07.10.2026
 *      Author: n3034770
 */


#include "distance.h"


Distance::Distance(int km, int m)
        :km(km), m(m)
{
}

int Distance::get_km() const
{
        return km;
}
int Distance::get_m() const
{
    return m;
}
int Distance::justmeters() const
{
    return km * 1000 + m;
}
bool Distance::add(const Distance& d)
{
        int total = justmeters() + d.justmeters();

        km = total / 1000;
        int rest = total % 1000;
        m = rest;

        return true;
}
bool Distance::add_km(int x)
{
        int total = justmeters() + x * 1000;

        if(total < 0)
        {
            km = 0;
            m = 0;
            return false;
        }
        km = total / 1000;
        int rest = total % 1000;
        m = rest;
        return true;
}

bool Distance::add_m(int x)
{
    int total = justmeters() + x;

    if(total < 0)
    {
        km = 0;
        m = 0;
        return false;
    }
    km = total / 1000;
    int rest = total % 1000;
    m = rest;
    return true;
}

int Distance::diff(const Distance& d) const
{
    return justmeters() - d.justmeters();
}


