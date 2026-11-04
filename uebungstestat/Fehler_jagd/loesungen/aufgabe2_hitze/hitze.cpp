#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "pbma.h"

using namespace std;

// Zehntelgrad als Grad mit einer Nachkommastelle
string grad(int zehntel) {
    string vorz = zehntel < 0 ? "-" : "";
    int betrag = zehntel < 0 ? -zehntel : zehntel;
    return vorz + to_string(betrag / 10) + "." + to_string(betrag % 10);
}

int main(int argc, const char* argv[]) {
    args_t args(argc, argv);
    string fname = args.pos(0, "juli.dat");
    int grenze = args.int_option("grenze", 300);
    bool verbose = args.flag("v");
    bool frost = args.flag("frost");
    string ziel = args.option("o", "");

    vector<int> werte = read_ints(fname);
    if (werte.empty() or werte[0] != static_cast<int>(werte.size()) - 1) {
        throw runtime_error("Anzahl stimmt nicht");
    }
    werte.erase(begin(werte));
    if (werte.empty()) {
        throw runtime_error("keine Tage");
    }

    int hitzetage{0};
    int laengste{0};
    int start_laengste{0};
    int aktuell{0};
    long summe{0};
    int frosttage{0};
    for (size_t i = 0; i < werte.size(); ++i) {
        bool heiss = werte[i] >= grenze;
        if (verbose) {
            cout << "Tag " << setw(2) << i + 1 << ": " << setw(5) << grad(werte[i])
                 << (heiss ? " *" : "") << endl;
        }
        summe += werte[i];
        if (werte[i] < 0) {
            frosttage += 1;
        }
        if (heiss) {
            hitzetage += 1;
            aktuell += 1;
            if (aktuell > laengste) {
                laengste = aktuell;
                start_laengste = static_cast<int>(i) + 2 - aktuell;
            }
        } else {
            aktuell = 0;
        }
    }

    ofstream datei;
    if (!ziel.empty()) {
        datei.open(ziel);
        if (!datei) {
            throw runtime_error("Datei nicht schreibbar: " + ziel);
        }
    }
    ostream& out = ziel.empty() ? cout : datei; // ein Ziel fuer beide Faelle

    out << "Tage: " << werte.size() << endl;
    out << "Hitzetage (>= " << grad(grenze) << "): " << hitzetage << endl;
    out << "Laengste Hitzeperiode: " << laengste << " Tage";
    if (laengste > 0) {
        out << " ab Tag " << start_laengste;
    }
    out << endl;
    if (frost) {
        out << "Frosttage: " << frosttage << endl;
    }
    out << "Mittel: " << fixed << setprecision(2)
        << static_cast<double>(summe) / 10.0 / static_cast<double>(werte.size())
        << endl;
}
