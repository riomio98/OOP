#include "Bitmenge.h"

#include <stdexcept>
#include <utility>

using namespace std;

size_t Bitmenge::bytes() const { return (_n + 7) / 8; }

void Bitmenge::pruefe(size_t i) const {
    if (i >= _n) {
        throw runtime_error("index out of range");
    }
}

Bitmenge::Bitmenge(size_t n) : _bytes(nullptr), _n(n) {
    if (n == 0) {
        throw runtime_error("invalid size");
    }
    _bytes = new unsigned char[bytes()]{}; // {} -> alle Bits 0
}

Bitmenge::Bitmenge(const Bitmenge& other) : _bytes(new unsigned char[other.bytes()]), _n(other._n) {
    for (size_t k = 0; k < bytes(); ++k) {
        _bytes[k] = other._bytes[k];
    }
}

void swap(Bitmenge& a, Bitmenge& b) noexcept {
    std::swap(a._bytes, b._bytes);
    std::swap(a._n, b._n);
}

Bitmenge& Bitmenge::operator=(Bitmenge other) {
    swap(*this, other);
    return *this;
}

Bitmenge::~Bitmenge() { delete[] _bytes; }

size_t Bitmenge::groesse() const { return _n; }

void Bitmenge::setze(size_t i) {
    pruefe(i);
    _bytes[i / 8] |= static_cast<unsigned char>(1u << (i % 8));
}

void Bitmenge::loesche(size_t i) {
    pruefe(i);
    _bytes[i / 8] &= static_cast<unsigned char>(~(1u << (i % 8)));
}

bool Bitmenge::ist_gesetzt(size_t i) const {
    pruefe(i);
    return (_bytes[i / 8] >> (i % 8)) & 1u;
}

size_t Bitmenge::anzahl() const {
    size_t z = 0;
    for (size_t i = 0; i < _n; ++i) {
        if (ist_gesetzt(i)) ++z;
    }
    return z;
}

Bitmenge& Bitmenge::vereinige(const Bitmenge& other) {
    if (other._n != _n) {
        throw runtime_error("size mismatch");
    }
    for (size_t k = 0; k < bytes(); ++k) {
        _bytes[k] |= other._bytes[k];
    }
    return *this;
}

void Bitmenge::out(ostream& os) const {
    for (size_t i = 0; i < _n; ++i) {
        os << (ist_gesetzt(i) ? '1' : '0');
    }
}
