#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include <string>

class Thermostat {
public:
    // explicit: static_assert is_convertible<double, Thermostat> muss false sein
    explicit Thermostat(double soll = 20.0, const std::string& raum = "Flur");
    ~Thermostat();
    Thermostat(const Thermostat&) = delete;            // nicht kopierbar
    Thermostat& operator=(const Thermostat&) = delete; // nicht zuweisbar

    double soll() const;                 // auf const Objekt aufgerufen
    const std::string& raum() const;     // gleiche Adresse -> Referenz
    bool stelle(double soll);            // false + begrenzen auf 5..30
    bool heizen(double ist) const;       // ct.heizen(...) -> const
    double& korrektur();                 // t.korrektur() = 1.5
    double korrektur() const;            // ct.korrektur()
    static int anzahl();                 // Thermostat::anzahl()

    // greift direkt auf private Attribute zu
    friend void synchronisiere(Thermostat& ziel, const Thermostat& quelle);

private:
    double _soll;
    const std::string _raum;
    double _korrektur;
    static int _anzahl;
};

void synchronisiere(Thermostat& ziel, const Thermostat& quelle);

#endif
