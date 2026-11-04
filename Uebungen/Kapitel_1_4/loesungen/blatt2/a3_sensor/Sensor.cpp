#include "Sensor.h"

#include <utility>

int Sensor::_naechste = 1;
int Sensor::_aktive = 0;
int Sensor::_hoechststand = 0;

int Sensor::neue_kennung() {
    ++_aktive;
    if (_aktive > _hoechststand) {
        _hoechststand = _aktive;
    }
    return _naechste++;
}

// _kennung ist const -> muss in der Initialisierungsliste gesetzt werden
Sensor::Sensor(double messwert) : _kennung(neue_kennung()), _messwert(messwert) {}

Sensor::Sensor(const Sensor& other) : _kennung(neue_kennung()), _messwert(other._messwert) {}

Sensor& Sensor::operator=(const Sensor& other) {
    _messwert = other._messwert; // Selbstzuweisung unkritisch
    return *this;
}

Sensor::~Sensor() { --_aktive; }

int Sensor::kennung() const { return _kennung; }
double Sensor::messwert() const { return _messwert; }
void Sensor::messe(double wert) { _messwert = wert; }
int Sensor::aktive() { return _aktive; }
int Sensor::hoechststand() { return _hoechststand; }

void tausche_messwerte(Sensor& a, Sensor& b) { std::swap(a._messwert, b._messwert); }
