#ifndef INTERVALL_H
#define INTERVALL_H

#include <iostream>

// Geschlossenes Intervall [von, bis] ganzer Zahlen, von <= bis.
class Intervall {
public:
    Intervall(int von = 0);           // Einpunktintervall; bewusst nicht explicit
    Intervall(int von, int bis);      // vertauschte Grenzen werden getauscht

    int von() const;
    int bis() const;
    int laenge() const;               // Anzahl enthaltener Zahlen

    bool enthaelt(int x) const;
    bool enthaelt(const Intervall& other) const;
    bool ueberlappt(const Intervall& other) const;

    Intervall& verschiebe(int d);     // fuer Verkettung
    Intervall vereinigung(const Intervall& other) const; // runtime_error("disjoint")

    void out(std::ostream& os = std::cout) const;        // "[3, 7]"

private:
    int _von;
    int _bis;
};

#endif
