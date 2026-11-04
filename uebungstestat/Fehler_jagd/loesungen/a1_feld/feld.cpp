#include "feld.h"

#include <stdexcept>

using namespace std;

void grenzen(const vector<int>& v, int& mn, int& mx) {
    if (v.empty()) {
        throw runtime_error("empty");
    }
    // FIX 1: mit dem ersten Element starten, nicht mit 0
    mn = v[0];
    mx = v[0];
    for (int x : v) {
        if (x < mn) {
            mn = x;
        }
        if (x > mx) {
            mx = x;
        }
    }
}

int& groesstes(vector<int>& v) {
    if (v.empty()) {
        throw runtime_error("empty");
    }
    size_t best = 0;
    for (size_t i = 1; i < v.size(); ++i) {
        if (v[i] > v[best]) {
            best = i;
        }
    }
    // FIX 2: Referenz auf das Element im Vektor, nicht auf eine lokale Kopie
    return v[best];
}

size_t entferne(vector<int>& v, int wert) {
    size_t anzahl = 0;
    // FIX 3: nach erase rueckt der Nachfolger auf Index i nach -> i nur
    // erhoehen, wenn nichts geloescht wurde
    size_t i = 0;
    while (i < v.size()) {
        if (v[i] == wert) {
            v.erase(begin(v) + i);
            ++anzahl;
        } else {
            ++i;
        }
    }
    return anzahl;
}

void tausche(int*& a, int*& b) {
    int* tmp = a;
    a = b;
    b = tmp;
}
