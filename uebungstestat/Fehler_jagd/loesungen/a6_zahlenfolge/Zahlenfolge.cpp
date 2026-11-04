#include "Zahlenfolge.h"

#include <stdexcept>

using namespace std;

Zahlenfolge::Zahlenfolge(size_t kapazitaet)
    : _daten(nullptr), _size(0), _cap(kapazitaet) {
    if (kapazitaet == 0) {
        throw runtime_error("invalid capacity");
    }
    _daten = new int[_cap];
}

// FIX 2: tiefe Kopie - eigener Freispeicher, Werte kopieren
Zahlenfolge::Zahlenfolge(const Zahlenfolge& other)
    : _daten(new int[other._cap]), _size(other._size), _cap(other._cap) {
    for (size_t i = 0; i < _size; ++i) {
        _daten[i] = other._daten[i];
    }
}

// FIX 3: Identitaetstest. Ohne ihn wird bei a = a erst der eigene Speicher
// freigegeben und danach aus dem freigegebenen Speicher kopiert.
// (Alternative: Copy & Swap, Skript 4.4 - dann ist kein Test noetig.)
Zahlenfolge& Zahlenfolge::operator=(const Zahlenfolge& other) {
    if (this == &other) {
        return *this;
    }
    delete[] _daten;
    _cap = other._cap;
    _size = other._size;
    _daten = new int[_cap];
    for (size_t i = 0; i < _size; ++i) {
        _daten[i] = other._daten[i];
    }
    return *this;
}

// FIX 1: mit new[] angelegt -> mit delete[] freigeben
Zahlenfolge::~Zahlenfolge() { delete[] _daten; }

size_t Zahlenfolge::size() const { return _size; }
size_t Zahlenfolge::capacity() const { return _cap; }

void Zahlenfolge::append(int wert) {
    if (_size == _cap) {
        size_t neue_cap = 2 * _cap;
        int* neu = new int[neue_cap];
        // FIX 4: alle _size Elemente umkopieren (vorher fehlte das letzte)
        for (size_t i = 0; i < _size; ++i) {
            neu[i] = _daten[i];
        }
        delete[] _daten;
        _daten = neu;
        _cap = neue_cap;
    }
    _daten[_size++] = wert;
}

int& Zahlenfolge::at(size_t i) {
    if (i >= _size) {
        throw runtime_error("index out of range");
    }
    return _daten[i];
}

int Zahlenfolge::at(size_t i) const {
    if (i >= _size) {
        throw runtime_error("index out of range");
    }
    return _daten[i];
}

long Zahlenfolge::summe() const {
    long s = 0;
    for (size_t i = 0; i < _size; ++i) {
        s += _daten[i];
    }
    return s;
}
