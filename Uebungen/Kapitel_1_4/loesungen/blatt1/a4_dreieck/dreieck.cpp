// Programm dreieck: Pascalsches Dreieck als "ausgefranstes" Feld im Freispeicher.
// Aufruf: dreieck [n] [-summe]
#include <iomanip>
#include <iostream>
#include <stdexcept>

#include "pbma.h"

using namespace std;

int** erzeuge(int n) {
    int** zeilen = new int*[n];
    for (int i = 0; i < n; ++i) {
        zeilen[i] = new int[i + 1];
        zeilen[i][0] = 1;
        zeilen[i][i] = 1;
        for (int k = 1; k < i; ++k) {
            zeilen[i][k] = zeilen[i - 1][k - 1] + zeilen[i - 1][k];
        }
    }
    return zeilen;
}

void freigeben(int** zeilen, int n) {
    for (int i = 0; i < n; ++i) {
        delete[] zeilen[i];
    }
    delete[] zeilen;
}

void ausgeben(int** zeilen, int n, bool summe) {
    for (int i = 0; i < n; ++i) {
        long s = 0;
        for (int k = 0; k <= i; ++k) {
            cout << setw(6) << zeilen[i][k];
            s += zeilen[i][k];
        }
        if (summe) {
            cout << "  = " << s;
        }
        cout << endl;
    }
}

int main(int argc, const char* argv[]) {
    try {
        args_t args(argc, argv);
        int n = args.int_pos(0, 5);
        if (n < 1 || n > 20) {
            throw runtime_error("n muss zwischen 1 und 20 liegen");
        }
        int** zeilen = erzeuge(n);
        ausgeben(zeilen, n, args.flag("summe"));
        cout << "Bytes: " << n * sizeof(int*) + n * (n + 1) / 2 * sizeof(int) << endl;
        freigeben(zeilen, n);
    } catch (const exception& e) {
        cerr << "Fehler: " << e.what() << endl;
        return 1;
    }
    return 0;
}
