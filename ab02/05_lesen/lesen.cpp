#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include "pbma.h"

using namespace std;

void print_nums(const int* zahlen, int anzahl, int from, int to,
                int min, int max, double avg, bool ausgabe)
{
    if (ausgabe)
    {
        for (int i = 0; i < anzahl; i++)
        {
            cout << from + i << ": " << zahlen[i] << endl;
        }
    }

    cout << "Anzahl der Zahlen in file: " << anzahl << endl;
    cout << "kleinste Zahl: " << min << endl;
    cout << "groesste Zahl: " << max << endl;
    cout << "average: " << avg << endl;
}

void number_statistics(const int* zahlen, int anzahl,
                       int& min, int& max, double& avg)
{
    int sum = 0;

    for (int i = 0; i < anzahl; i++)
    {
        sum += zahlen[i];

        if (zahlen[i] < min)
            min = zahlen[i];

        if (zahlen[i] > max)
            max = zahlen[i];
    }

    avg = (float)sum / anzahl;
}

int main(int argc, const char* argv[])
{
    args_t args(argc, argv);

    string fname = args.pos(0, "zahlen.dat");
    string from_arg = args.pos(1, "");
    string to_arg = args.pos(2, "");

    ifstream datei(fname);


    int anzahl;

    if (!(datei >> anzahl) or anzahl <= 0)
    {
        cerr << "Ungülige anz. Zalen." << endl;
        return 1;
    }

    int from = 0;
    int to = anzahl;

    if (!from_arg.empty())
        from = stoi(from_arg);

    if (!to_arg.empty())
        to = stoi(to_arg);

    if (from < 0 or to > anzahl or from >= to)
    {
        cerr << "Ungueltiger Bereich." << endl;
        return 1;
    }

    int bereich = to - from;
    int* zahlen = new int[bereich];

    int wert;

    for (int i = 0; i < from; i++)
        datei >> wert;

    for (int i = 0; i < bereich; i++)
    {
        if (!(datei >> zahlen[i]))
        {
            cerr << "Fehler beim Lesen der Zahlen." << endl;
            delete[] zahlen;
            return 1;
        }
    }

    int min = numeric_limits<int>::max();
    int max = numeric_limits<int>::min();
    double avg = 0.0f;

    number_statistics(zahlen, bereich, min, max, avg);

    print_nums(zahlen, bereich, from, to,
               min, max, avg, args.flag("v"));

    delete[] zahlen;

    return 0;
}
