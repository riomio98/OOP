#ifndef DATUM_H
#define DATUM_H

#include <iostream>

// Kalenderdatum (gregorianisch). Vorgabe 01.01.1970.
// Ungueltige Angaben: std::runtime_error("invalid date").
class Datum {
public:
    Datum(int tag = 1, int monat = 1, int jahr = 1970);

    int tag() const;
    int monat() const;
    int jahr() const; // FIX 1: const fehlte

    static bool schaltjahr(int jahr);
    static int tage_im_monat(int monat, int jahr);

    void naechster_tag();
    void addiere_tage(int n); // n < 0: std::runtime_error("negative days")
    bool vor(const Datum& other) const;
    void out(std::ostream& os = std::cout) const; // Format TT.MM.JJJJ

private:
    int _tag;
    int _monat;
    int _jahr;
};

#endif
