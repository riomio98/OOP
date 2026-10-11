/*
 * main.cpp
 *
 *  Created on: 06.10.2026
 *      Author: n3034770
 */




#include<iostream>
#include <vector>
#include <string>
#include "Time.h"


using namespace std;



int main()
{
    Time a(1, 1, 1);

    cout << "Start: "
         << a.getHour() << ":"
         << a.getMinute() << ":"
         << a.getSecond() << endl;

    a.add_hour(1);
    a.add_minute(1);
    a.add_second(1);

    cout << "Nach add: "
         << a.getHour() << ":"
         << a.getMinute() << ":"
         << a.getSecond() << endl;

    Time b(1, 0, 0);

    a.add(b);
    cout << "diff: " << a.diff(b) << endl;

    Time c(0, 0, 10);
    cout << "negativ: " << c.add_second(-20) << endl;

    Time d(12,0,0);

    cout << "Overflow-Test: "
         << d.add_second(2147483647) << endl;

    return 0;
}
