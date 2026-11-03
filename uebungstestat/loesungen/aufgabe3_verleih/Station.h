#ifndef STATION_H
#define STATION_H

#include <cstddef>
#include <string>

#include "Fahrrad.h"

class Station {
public:
    Station(const std::string& name, size_t plaetze);
    Station(const Station& other);
    Station& operator=(const Station& other);
    ~Station();

    const std::string& name() const { return _name; }
    size_t plaetze() const { return _plaetze; }
    size_t belegt() const;
    size_t frei() const { return _plaetze - belegt(); }

    bool einstellen(Fahrrad& f);
    Fahrrad* entnehmen(int nummer);
    Fahrrad* finde(int nummer);
    const Fahrrad* finde(int nummer) const;
    int wartungsbedarf(int intervall = 500) const;

private:
    std::string _name;
    size_t _plaetze;
    Fahrrad** _platz; // nicht besitzend: Station loescht keine Fahrraeder
};

#endif
