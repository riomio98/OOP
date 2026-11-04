#ifndef TICKET_H
#define TICKET_H

#include <string>

// Ein Ticket fuer einen Kunden. Nummern werden ab 1 fortlaufend vergeben.
// Eine Kopie ist ein weiteres aktives Ticket mit derselben Nummer.
// aktive() zaehlt alle aktuell existierenden Tickets (auch Kopien).
class Ticket {
public:
	explicit Ticket(const std::string &kunde); // leer: runtime_error("kein Kunde")
	~Ticket();

	int nr() const;
	const std::string& kunde() const;
	static int aktive();

private:
	int _nr;
	std::string _kunde;
	static int _naechste_nr;
	static int _aktive;
};
#endif
