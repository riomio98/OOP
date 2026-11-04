#include "Thermostat.h"

#include <stdexcept>

using namespace std;

namespace {
const double MIN_SOLL = 5.0;
const double MAX_SOLL = 30.0;
}

int Thermostat::_anzahl = 0;

Thermostat::Thermostat(double soll, const string& raum)
    : _soll(soll), _raum(raum), _korrektur(0.0) {
    if (soll < MIN_SOLL || soll > MAX_SOLL) {
        throw runtime_error("invalid temperature");
    }
    if (raum.empty()) {
        throw runtime_error("invalid room");
    }
    ++_anzahl; // erst nach allen Pruefungen zaehlen
}

Thermostat::~Thermostat() { --_anzahl; }

double Thermostat::soll() const { return _soll; }
const string& Thermostat::raum() const { return _raum; }

bool Thermostat::stelle(double soll) {
    if (soll < MIN_SOLL) {
        _soll = MIN_SOLL;
        return false;
    }
    if (soll > MAX_SOLL) {
        _soll = MAX_SOLL;
        return false;
    }
    _soll = soll;
    return true;
}

bool Thermostat::heizen(double ist) const { return ist + _korrektur < _soll; }

double& Thermostat::korrektur() { return _korrektur; }
double Thermostat::korrektur() const { return _korrektur; }

int Thermostat::anzahl() { return _anzahl; }

void synchronisiere(Thermostat& ziel, const Thermostat& quelle) {
    ziel._soll = quelle._soll;
}
