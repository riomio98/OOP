#include "Belegungsplan.h"

#include <stdexcept>

using namespace std;

Belegungsplan::Belegungsplan(const string& raum, const Intervall& oeffnung)
    : _raum(raum), _oeffnung(oeffnung) {}

const string& Belegungsplan::raum() const { return _raum; }
const Intervall& Belegungsplan::oeffnung() const { return _oeffnung; }

bool Belegungsplan::reservieren(const Intervall& zeit) {
    if (!_oeffnung.enthaelt(zeit)) {
        return false;
    }
    for (const Intervall& r : _belegt) {
        if (r.ueberlappt(zeit)) {
            return false;
        }
    }
    _belegt.push_back(zeit);
    return true;
}

bool Belegungsplan::stornieren(int minute) {
    for (size_t i = 0; i < _belegt.size(); ++i) {
        if (_belegt[i].enthaelt(minute)) {
            _belegt.erase(begin(_belegt) + i);
            return true;
        }
    }
    return false;
}

size_t Belegungsplan::anzahl() const { return _belegt.size(); }

const Intervall& Belegungsplan::reservierung(size_t i) const {
    if (i >= _belegt.size()) {
        throw runtime_error("index out of range");
    }
    return _belegt[i];
}

int Belegungsplan::belegte_minuten() const {
    int summe = 0;
    for (const Intervall& r : _belegt) {
        summe += r.laenge();
    }
    return summe;
}

int Belegungsplan::freie_minuten() const { return _oeffnung.laenge() - belegte_minuten(); }
