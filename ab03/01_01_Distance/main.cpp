/*
 * main.cpp
 *
 *  Created on: 08.10.2026
 *      Author: n3034770
 */
#include <iostream>
#include "distance.h"

using namespace std;

int main()
{
    Distance d1(10, 500);
    Distance d2(5, 500);
    Distance d3;

    cout << "Anfangs Werte:" << endl;

    cout << "d1: "
         << "km: " << d1.get_km()
         << " m: " << d1.get_m()
         << " total meters: " << d1.justmeters()
         << endl;

    cout << "d2: "
         << "km: " << d2.get_km()
         << " m: " << d2.get_m()
         << " total meters: " << d2.justmeters()
         << endl;

    cout << "d3: "
         << "km: " << d3.get_km()
         << " m: " << d3.get_m()
         << " total meters: " << d3.justmeters()
         << endl;

    cout << endl;

    // negative Tests
    cout << "Negative Fail tests d1:" << endl;

    cout << "minus 11 km: "
         << d1.add_km(-11)
         << endl;

    cout << "minus 501 m: "
         << d1.add_m(-501)
         << endl;

    cout << "d1: "
         << "km: " << d1.get_km()
         << " m: " << d1.get_m()
         << " total meters: " << d1.justmeters()
         << endl;

    cout << endl;

    cout << "add d2 to d1: "
         << d1.add(d2)
         << endl;

    cout << "d1: "
         << "km: " << d1.get_km()
         << " m: " << d1.get_m()
         << " total meters: " << d1.justmeters()
         << endl;

    cout << "d2: "
         << "km: " << d2.get_km()
         << " m: " << d2.get_m()
         << " total meters: " << d2.justmeters()
         << endl;

    cout << endl;

    cout << "difference d3 - d1: "
         << d3.diff(d1)
         << endl;

    return 0;
}



