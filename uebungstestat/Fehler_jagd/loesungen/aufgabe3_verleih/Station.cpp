#include "Station.h"

#include <stdexcept>
#include <utility>

Station::Station(const std::string& name, size_t plaetze)
    : _name{name}, _plaetze{plaetze}, _platz{nullptr} {
    if (plaetze == 0) {
        throw std::runtime_error("invalid size");
    }
    _platz = new Fahrrad*[plaetze]{}; // alle nullptr
}

Station::Station(const Station& other)
    : _name{other._name}, _plaetze{other._plaetze},
      _platz{new Fahrrad*[other._plaetze]} {
    for (size_t i = 0; i < _plaetze; ++i) {
        _platz[i] = other._platz[i];
    }
}

Station& Station::operator=(const Station& other) {
    Station tmp{other};
    std::swap(_name, tmp._name);
    std::swap(_plaetze, tmp._plaetze);
    std::swap(_platz, tmp._platz);
    return *this;
}

Station::~Station() {
    delete[] _platz; // nur das Zeigerfeld, nicht die Fahrraeder
}

size_t Station::belegt() const {
    size_t n{0};
    for (size_t i = 0; i < _plaetze; ++i) {
        if (_platz[i] != nullptr) {
            n += 1;
        }
    }
    return n;
}

bool Station::einstellen(Fahrrad& f) {
    if (f.ausgeliehen() or finde(f.nummer()) != nullptr) {
        return false;
    }
    for (size_t i = 0; i < _plaetze; ++i) {
        if (_platz[i] == nullptr) {
            _platz[i] = &f;
            return true;
        }
    }
    return false; // voll
}

Fahrrad* Station::entnehmen(int nummer) {
    for (size_t i = 0; i < _plaetze; ++i) {
        if (_platz[i] != nullptr and _platz[i]->nummer() == nummer) {
            Fahrrad* f = _platz[i];
            _platz[i] = nullptr;
            return f;
        }
    }
    return nullptr;
}

Fahrrad* Station::finde(int nummer) {
    for (size_t i = 0; i < _plaetze; ++i) {
        if (_platz[i] != nullptr and _platz[i]->nummer() == nummer) {
            return _platz[i];
        }
    }
    return nullptr;
}

const Fahrrad* Station::finde(int nummer) const {
    for (size_t i = 0; i < _plaetze; ++i) {
        if (_platz[i] != nullptr and _platz[i]->nummer() == nummer) {
            return _platz[i];
        }
    }
    return nullptr;
}

int Station::wartungsbedarf(int intervall) const {
    int n{0};
    for (size_t i = 0; i < _plaetze; ++i) {
        if (_platz[i] != nullptr and _platz[i]->braucht_wartung(intervall)) {
            n += 1;
        }
    }
    return n;
}
