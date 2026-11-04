#include "Intervall.h"

#include <algorithm>
#include <stdexcept>

using namespace std;

Intervall::Intervall(int von) : Intervall(von, von) {}

Intervall::Intervall(int von, int bis) : _von(min(von, bis)), _bis(max(von, bis)) {}

int Intervall::von() const { return _von; }
int Intervall::bis() const { return _bis; }
int Intervall::laenge() const { return _bis - _von + 1; }

bool Intervall::enthaelt(int x) const { return _von <= x && x <= _bis; }

bool Intervall::enthaelt(const Intervall& other) const {
    return _von <= other._von && other._bis <= _bis;
}

bool Intervall::ueberlappt(const Intervall& other) const {
    return _von <= other._bis && other._von <= _bis;
}

Intervall& Intervall::verschiebe(int d) {
    _von += d;
    _bis += d;
    return *this;
}

Intervall Intervall::vereinigung(const Intervall& other) const {
    // ueberlappend oder direkt angrenzend (z. B. [1, 3] und [4, 6])
    if (_bis + 1 < other._von || other._bis + 1 < _von) {
        throw runtime_error("disjoint");
    }
    return Intervall(min(_von, other._von), max(_bis, other._bis));
}

void Intervall::out(ostream& os) const { os << "[" << _von << ", " << _bis << "]"; }
