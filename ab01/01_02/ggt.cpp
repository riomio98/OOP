/*
 * ggt.cpp
 *
 *  Created on: 24.09.2026
 *      Author: n3034770
 */
#include <iostream>
#include <string>

using namespace std;

int ggt1(int a, int b)
{
    while(a != b)
    {
        if(a > b)
        {
            a = a - b;
        }
        else if(b > a)
        {
            b = b - a;
        }
    }
    return a;
}

int ggt2(int a, int b)
{
    while(a != 0 && b != 0)
    {
        if(a > b)
        {
            a = a % b;
        }
        else if(b > a)
        {
            b = b % a;
        }
    }
    if(a == 0)
        return b;
    else
        return a;
}

int main()
{
    int a = 45;
    int b = 10;

    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "ggt1: " << ggt1(a, b) << endl;
    cout << "ggt2: " << ggt1(a, b) << endl;

    return 0;
}
