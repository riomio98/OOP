
#include <iostream>
#include <limits>
#include "Time.h"

using namespace std;

int main()
{
    Time a(1, 1, 1);

    cout << "Start: ";
    a.print();
    cout << endl;

    a.add_hours(1);
    a.add_minutes(1);
    a.add_seconds(1);

    cout << "Nach add: ";
    a.print();
    cout << endl;

    Time b(1, 0, 0);

    a.add(b);
    cout << "diff: " << a.diff(b) << endl;

    cout << "Sekunden: " << a.justseconds() << endl;

    cout << "Stunden: " << a.hour() << endl;
    cout << "Minuten: " << a.minute() << endl;
    cout << "Sekundenanteil: " << a.second() << endl;

    Time c(0, 0, 10);

    cout << "negativ: " << c.add_seconds(-20) << endl;
    c.print();


    Time d(30, 70, 90);
    d.print();

    Time e(numeric_limits<int>::max(), 59,59);
    cout << "Overflow check: "<< e.add_hours(1) << endl;
    e.print();



    return 0;
}
