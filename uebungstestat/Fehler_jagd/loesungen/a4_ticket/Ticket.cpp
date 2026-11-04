#include "Ticket.h"

#include <stdexcept>

using namespace std;

int Ticket::_naechste_nr = 1;
int Ticket::_aktive = 0;

// FIX 1: erst pruefen, dann zaehlen. Wirft der Konstruktor, existiert kein
// Objekt, der Destruktor laeuft nicht - Zaehler und Nummer waeren verloren.
Ticket::Ticket(const string& kunde) : _nr(0), _kunde(kunde) {
    if (kunde.empty()) {
        throw runtime_error("kein Kunde");
    }
    _nr = _naechste_nr++;
    ++_aktive;
}

// FIX 2: Der automatisch erzeugte Kopierkonstruktor zaehlt nicht hoch,
// der Destruktor der Kopie zaehlt aber herunter.
Ticket::Ticket(const Ticket& other) : _nr(other._nr), _kunde(other._kunde) {
    ++_aktive;
}

Ticket::~Ticket() { --_aktive; }

int Ticket::nr() const { return _nr; }
const string& Ticket::kunde() const { return _kunde; }
int Ticket::aktive() { return _aktive; }
