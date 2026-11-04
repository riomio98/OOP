#include "feld.h"

#include <stdexcept>

using namespace std;

void grenzen(const vector<int>& v, int& mn, int& mx) {
    if (v.empty()) {
        throw runtime_error("empty");
    }
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
    return v[best];
}

size_t entferne(vector<int>& v, int wert) {
    size_t anzahl = 0;
    for (size_t i = 0; i < v.size();) {
        if (v[i] == wert) {
            v.erase(begin(v) + i);
            ++anzahl;
        }
        else
        {
        	i++;
        }

    }
    return anzahl;
}

void tausche(int*& a, int*& b) {
    int* tmp = a;
    a = b;
    b = tmp;
}
