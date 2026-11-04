#ifndef TEAM_H
#define TEAM_H

#include <cstddef>
#include <string>
#include <vector>

#include "Laeufer.h"

class Team {
public:
    static const std::size_t MAX = 4;

    explicit Team(const std::string& name);

    const std::string& name() const;
    std::size_t groesse() const;
    bool aufnehmen(const Laeufer& l);      // false, wenn schon MAX Laeufer
    int gesamtzeit() const;
    const Laeufer& schnellster() const;    // leer: runtime_error("leer")
    Laeufer& laeufer(std::size_t i);       // runtime_error("index out of range")
    const Laeufer& laeufer(std::size_t i) const;

private:
    std::string _name;
    std::vector<Laeufer> _laeufer;
};

#endif
