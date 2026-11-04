#include "Datum.h"

#include <iomanip>
#include <stdexcept>

using namespace std;

Datum::Datum(int tag, int monat, int jahr) : _tag(tag), _monat(monat), _jahr(jahr) {
    if (monat < 1 || monat > 12 || tag < 1 || tag > tage_im_monat(monat, jahr)) {
        throw runtime_error("invalid date");
    }
}

int Datum::tag() const { return _tag; }
int Datum::monat() const { return _monat; }
int Datum::jahr() const { return _jahr; }

bool Datum::schaltjahr(int jahr) {
    return (jahr % 4 == 0 && jahr % 100 != 0) || (jahr%400 ==0);
}

int Datum::tage_im_monat(int monat, int jahr) {
    switch (monat) {
    case 2:
        return schaltjahr(jahr) ? 29 : 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

void Datum::naechster_tag() {
    ++_tag;
    if (_tag > tage_im_monat(_monat, _jahr)) {
        _tag = 1;
        ++_monat;
        if (_monat > 12) {
            _monat = 1;
            _jahr++;
        }
    }
}

void Datum::addiere_tage(int n) {
    if (n < 0) {
        throw runtime_error("negative days");
    }
    for (int i = 0; i < n; ++i) {
        naechster_tag();
    }
}

bool Datum::vor(const Datum& other) const {

	return (10000 * _jahr + 100 * _monat + _tag) <
		(10000 * other._jahr + 100 * other._monat + other._tag) ;
}

void Datum::out(ostream& os) const {
    os << setfill('0') << setw(2) << _tag << "." << setw(2) << _monat << "."
       << setw(4) << _jahr << setfill(' ');
}
