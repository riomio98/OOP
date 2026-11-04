#include "Ringpuffer.h"

#include <stdexcept>
#include <utility>

Ringpuffer::Ringpuffer(size_t kapazitaet)
    : _cap{kapazitaet}, _start{0}, _size{0}, _data{nullptr} {
    if (kapazitaet == 0) {
        throw std::runtime_error("invalid capacity");
    }
    _data = new int[kapazitaet];
}

Ringpuffer::Ringpuffer(const Ringpuffer& other)
    : _cap{other._cap}, _start{other._start}, _size{other._size},
      _data{new int[other._cap]} {
    for (size_t i = 0; i < _cap; ++i) {
        _data[i] = other._data[i];
    }
}

Ringpuffer& Ringpuffer::operator=(const Ringpuffer& other) {
    Ringpuffer tmp{other};
    std::swap(_cap, tmp._cap);
    std::swap(_start, tmp._start);
    std::swap(_size, tmp._size);
    std::swap(_data, tmp._data);
    return *this;
}

Ringpuffer::~Ringpuffer() {
    delete[] _data;
}

Ringpuffer& Ringpuffer::add(int wert) {
    if (_size < _cap) {
        _data[(_start + _size) % _cap] = wert;
        _size += 1;
    } else { // voll: aeltesten ueberschreiben
        _data[_start] = wert;
        _start = (_start + 1) % _cap;
    }
    return *this;
}

int& Ringpuffer::at(size_t i) {
    if (i >= _size) {
        throw std::runtime_error("index out of range");
    }
    return _data[(_start + i) % _cap];
}

int Ringpuffer::at(size_t i) const {
    if (i >= _size) {
        throw std::runtime_error("index out of range");
    }
    return _data[(_start + i) % _cap];
}

double Ringpuffer::mittel() const {
    if (_size == 0) {
        throw std::runtime_error("empty");
    }
    long summe{0};
    for (size_t i = 0; i < _size; ++i) {
        summe += at(i);
    }
    return static_cast<double>(summe) / static_cast<double>(_size);
}

int Ringpuffer::neuester() const {
    if (_size == 0) {
        throw std::runtime_error("empty");
    }
    return at(_size - 1);
}

void Ringpuffer::resize(size_t neue_kapazitaet) {
    if (neue_kapazitaet == 0) {
        throw std::runtime_error("invalid capacity");
    }
    size_t behalten = _size < neue_kapazitaet ? _size : neue_kapazitaet;
    int* neu = new int[neue_kapazitaet];
    for (size_t i = 0; i < behalten; ++i) { // die neuesten, aeltester zuerst
        neu[i] = at(_size - behalten + i);
    }
    delete[] _data;
    _data = neu;
    _cap = neue_kapazitaet;
    _start = 0;
    _size = behalten;
}
