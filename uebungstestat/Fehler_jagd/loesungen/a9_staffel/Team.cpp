#include "Team.h"

#include <stdexcept>

using namespace std;

Team::Team(const string& name) : _name(name) {}

const string& Team::name() const { return _name; }
size_t Team::groesse() const { return _laeufer.size(); }

bool Team::aufnehmen(const Laeufer& l) {
    if (_laeufer.size() >= MAX) {
        return false;
    }
    _laeufer.push_back(l); // speichert eine Kopie
    return true;
}

int Team::gesamtzeit() const {
    int summe = 0;
    for (const Laeufer& l : _laeufer) {
        summe += l.zeit();
    }
    return summe;
}

const Laeufer& Team::schnellster() const {
    if (_laeufer.empty()) {
        throw runtime_error("leer");
    }
    size_t best = 0;
    for (size_t i = 1; i < _laeufer.size(); ++i) {
        if (_laeufer[i].zeit() < _laeufer[best].zeit()) {
            best = i;
        }
    }
    return _laeufer[best];
}

Laeufer& Team::laeufer(size_t i) {
    if (i >= _laeufer.size()) {
        throw runtime_error("index out of range");
    }
    return _laeufer[i];
}

const Laeufer& Team::laeufer(size_t i) const {
    if (i >= _laeufer.size()) {
        throw runtime_error("index out of range");
    }
    return _laeufer[i];
}
