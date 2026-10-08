/*
 * ggt.cpp
 *
 *  Created on: 24.09.2026
 *      Author: n3034770
 */

#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main()
{
    cout << setw(20) << "int" << " " << sizeof(int) << ": ";
    cout << setw(20) << numeric_limits<int>::min() << " .. ";
    cout << setw(20) << numeric_limits<int>::max() << endl;

    cout << setw(20) << "double" << " " << sizeof(double) << ": ";
    cout << setw(20) << numeric_limits<double>::min() << " .. ";
    cout << setw(20) << numeric_limits<double>::max() << endl;

    cout << setw(20) << "float" << " " << sizeof(float) << ": ";
    cout << setw(20) << numeric_limits<float>::min() << " .. ";
    cout << setw(20) << numeric_limits<float>::max() << endl;

    cout << setw(20) << "unsigned int" << " " << sizeof(unsigned int) << ": ";
    cout << setw(20) << numeric_limits<unsigned int>::min() << " .. ";
    cout << setw(20) << numeric_limits<unsigned int>::max() << endl;
    return 0;
 }


