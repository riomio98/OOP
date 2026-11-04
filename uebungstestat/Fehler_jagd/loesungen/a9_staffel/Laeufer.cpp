#include "Laeufer.h"

#include <iomanip>
#include <sstream>
#include <stdexcept>

using namespace std;

Laeufer::Laeufer(const string& name, int zeit) : _name(name), _zeit(zeit) {
    if (name.empty()) {
        throw runtime_error("kein Name");
    }
    if (zeit < 0) {
        throw runtime_error("negative Zeit");
    }
}

const string& Laeufer::name() const { return _name; }
int Laeufer::zeit() const { return _zeit; }

bool Laeufer::setze_zeit(int zeit) {
    if (zeit < 0) {
        return false;
    }
    _zeit = zeit;
    return true;
}

string Laeufer::anzeige() const {
    ostringstream os;
    os << _name << " (" << _zeit / 60 << ":" << setw(2) << setfill('0') << _zeit % 60 << ")";
    return os.str();
}
