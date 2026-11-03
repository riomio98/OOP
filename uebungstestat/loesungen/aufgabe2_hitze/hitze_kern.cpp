// Nur Teil a) - die Loesung mit Variation b) steht in hitze.cpp
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
    for (size_t i = 0; i < werte.size(); ++i) {
        bool heiss = werte[i] >= grenze;
        if (verbose) {
            cout << "Tag " << setw(2) << i + 1 << ": " << setw(5) << grad(werte[i])
                 << (heiss ? " *" : "") << endl;
        }
        summe += werte[i];
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

    cout << "Tage: " << werte.size() << endl;
    cout << "Hitzetage (>= " << grad(grenze) << "): " << hitzetage << endl;
    cout << "Laengste Hitzeperiode: " << laengste << " Tage";
    if (laengste > 0) {
        cout << " ab Tag " << start_laengste;
    }
    cout << endl;
    cout << "Mittel: " << fixed << setprecision(2)
         << static_cast<double>(summe) / 10.0 / static_cast<double>(werte.size())
         << endl;
}
