#include "Ticket.h"

#include <stdexcept>

using namespace std;

int Ticket::_naechste_nr = 1;
int Ticket::_aktive = 0;

Ticket::Ticket(const string& kunde) : _nr(_naechste_nr++), _kunde(kunde) {
    ++_aktive;
    if (kunde.empty()) {
        throw runtime_error("kein Kunde");
    }
}

Ticket::~Ticket() { --_aktive; }

int Ticket::nr() const { return _nr; }
const string& Ticket::kunde() const { return _kunde; }
int Ticket::aktive() { return _aktive; }
