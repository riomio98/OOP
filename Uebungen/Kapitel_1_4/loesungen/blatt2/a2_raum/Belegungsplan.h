#ifndef BELEGUNGSPLAN_H
#define BELEGUNGSPLAN_H

#include <cstddef>
#include <string>
#include <vector>

#include "Intervall.h"

// Reservierungen eines Raums an einem Tag, Zeiten in Minuten ab 0:00.
class Belegungsplan {
public:
    explicit Belegungsplan(const std::string& raum,
                           const Intervall& oeffnung = Intervall(480, 1199));

    const std::string& raum() const;
    const Intervall& oeffnung() const;
    bool reservieren(const Intervall& zeit);
    bool stornieren(int minute);
    std::size_t anzahl() const;
    const Intervall& reservierung(std::size_t i) const; // runtime_error("index out of range")
    int belegte_minuten() const;
    int freie_minuten() const;

private:
    const std::string _raum;
    const Intervall _oeffnung;
    std::vector<Intervall> _belegt;
};

#endif
