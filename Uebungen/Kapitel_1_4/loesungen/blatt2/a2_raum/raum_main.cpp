// Programm raum: liest Reservierungswuensche (Paare von Minuten) und bucht sie.
// Aufruf: raum [datei] [-raum=Name]
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Belegungsplan.h"
#include "Intervall.h"
#include "pbma.h"

using namespace std;

string uhr(int minute) {
    ostringstream os;
    os << setfill('0') << setw(2) << minute / 60 << ":" << setw(2) << minute % 60;
    return os.str();
}

int main(int argc, const char* argv[]) {
    try {
        args_t args(argc, argv);
        string name = args.pos(0, "wuensche.dat");
        vector<int> z = read_ints(name);
        if (z.size() % 2 != 0) {
            throw runtime_error("ungerade Anzahl von Zahlen in " + name);
        }
        Belegungsplan plan(args.option("raum", "A101"));
        for (size_t i = 0; i < z.size(); i += 2) {
            Intervall wunsch(z[i], z[i + 1]);
            bool ok = plan.reservieren(wunsch);
            cout << uhr(wunsch.von()) << "-" << uhr(wunsch.bis()) << " "
                 << (ok ? "ok" : "abgelehnt") << endl;
        }
        cout << "Raum " << plan.raum() << ": " << plan.anzahl() << " Reservierungen, "
             << plan.belegte_minuten() << " min belegt, " << plan.freie_minuten()
             << " min frei" << endl;
    } catch (const exception& e) {
        cerr << "Fehler: " << e.what() << endl;
        return 1;
    }
    return 0;
}
