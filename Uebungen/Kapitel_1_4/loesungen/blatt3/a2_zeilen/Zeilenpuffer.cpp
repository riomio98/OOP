#include "Zeilenpuffer.h"

#include <stdexcept>

using namespace std;

Zeilenpuffer::Zeilenpuffer(size_t kapazitaet) : _zeilen(nullptr), _size(0), _cap(kapazitaet) {
    if (kapazitaet == 0) {
        throw runtime_error("invalid capacity");
    }
    _zeilen = new string[_cap];
}

Zeilenpuffer::Zeilenpuffer(const Zeilenpuffer& other)
    : _zeilen(new string[other._cap]), _size(other._size), _cap(other._cap) {
    for (size_t i = 0; i < _size; ++i) {
        _zeilen[i] = other._zeilen[i];
    }
}

Zeilenpuffer& Zeilenpuffer::operator=(const Zeilenpuffer& other) {
    if (this == &other) {
        return *this;
    }
    delete[] _zeilen;
    _cap = other._cap;
    _size = other._size;
    _zeilen = new string[_cap];
    for (size_t i = 0; i < _size; ++i) {
        _zeilen[i] = other._zeilen[i];
    }
    return *this;
}

Zeilenpuffer::~Zeilenpuffer() { delete[] _zeilen; }

size_t Zeilenpuffer::size() const { return _size; }
size_t Zeilenpuffer::kapazitaet() const { return _cap; }

void Zeilenpuffer::anhaengen(const string& zeile) {
    if (_size == _cap) {
        string* neu = new string[2 * _cap];
        for (size_t i = 0; i < _size; ++i) {
            neu[i] = _zeilen[i];
        }
        delete[] _zeilen;
        _zeilen = neu;
        _cap *= 2;
    }
    _zeilen[_size++] = zeile;
}

string& Zeilenpuffer::zeile(size_t i) {
    if (i >= _size) {
        throw runtime_error("index out of range");
    }
    return _zeilen[i];
}

const string& Zeilenpuffer::zeile(size_t i) const {
    if (i >= _size) {
        throw runtime_error("index out of range");
    }
    return _zeilen[i];
}

void Zeilenpuffer::entferne(size_t i) {
    if (i >= _size) {
        throw runtime_error("index out of range");
    }
    for (size_t k = i; k + 1 < _size; ++k) {
        _zeilen[k] = _zeilen[k + 1];
    }
    --_size;
    _zeilen[_size].clear(); // Inhalt hinter dem Ende wird nicht mehr gebraucht
}

size_t Zeilenpuffer::finde(const string& wort, size_t ab) const {
    for (size_t i = ab; i < _size; ++i) {
        if (_zeilen[i].find(wort) != string::npos) {
            return i;
        }
    }
    return _size;
}
