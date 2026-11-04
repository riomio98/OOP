#include "Fahrrad.h"

#include <stdexcept>
#include <utility>

int Fahrrad::_naechste_nummer{1001};
int Fahrrad::_unterwegs{0};

Fahrrad::Fahrrad(const std::string& modell, int km)
    : _nummer{_naechste_nummer}, _modell{modell}, _km{km} {
    if (km < 0) {
        throw std::runtime_error("negative km");
    }
    _naechste_nummer += 1; // Nummer erst nach erfolgreicher Pruefung verbrauchen
}

Fahrrad::~Fahrrad() {
    if (_ausgeliehen) {
        _unterwegs -= 1;
    }
}

bool Fahrrad::ausleihen() {
    if (_ausgeliehen) {
        return false;
    }
    _ausgeliehen = true;
    _unterwegs += 1;
    return true;
}

bool Fahrrad::zurueckgeben(int gefahren) {
    if (not _ausgeliehen or gefahren < 0) {
        return false;
    }
    _ausgeliehen = false;
    _unterwegs -= 1;
    _km += gefahren;
    _seit_wartung += gefahren;
    return true;
}

bool Fahrrad::braucht_wartung(int intervall) const {
    return _seit_wartung >= intervall;
}

bool Fahrrad::warten() {
    if (_ausgeliehen) {
        return false;
    }
    _seit_wartung = 0;
    return true;
}

bool tausche_modell(Fahrrad& a, Fahrrad& b) {
    if (&a == &b or a._ausgeliehen or b._ausgeliehen) {
        return false;
    }
    std::swap(a._modell, b._modell);
    return true;
}
