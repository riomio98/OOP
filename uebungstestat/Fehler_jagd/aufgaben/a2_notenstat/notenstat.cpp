// notenstat: wertet eine Datei mit Klausurpunkten aus.
// Aufruf: notenstat [datei] [-grenze=N] [-v]
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "pbma.h"

using namespace std;

// Liest die Datei: erste Zahl = Anzahl, danach die Punkte.
vector<int> lies_punkte(const string& name) {
    ifstream datei(name);
    if (!datei) {
        throw runtime_error("Datei nicht lesbar: " + name);
    }
    size_t anzahl = 0;
    if (!(datei >> anzahl)) {
        throw runtime_error("Anzahl fehlt in " + name);
    }
    vector<int> punkte;
    int x = 0;
    while (datei >> x) {
        punkte.push_back(x);
    }
    if (punkte.size() != anzahl || anzahl == 0) {
        throw runtime_error("Anzahl passt nicht in " + name);
    }
    return punkte;
}

void auswerten(const vector<int>& punkte, int grenze, bool verbose) {
    if (verbose) {
        for (size_t i = 0; i < punkte.size(); ++i) {
            cout << "Nr " << setw(2) << i + 1 << ": " << setw(3) << punkte[i] << endl;
        }
    }
    int summe = 0;
    int bestanden = 0;
    size_t best = 0;
    for (size_t i = 0; i < punkte.size(); ++i) {
        summe += punkte[i];
        if (punkte[i] >= grenze) {
            ++bestanden;
        }
        if (punkte[i] > punkte[best]) {
            best = i;
        }
    }
    double n = static_cast<double>(punkte.size());
    double schnitt = summe / n;
    cout << "Teilnehmer: " << n << endl;
    cout << "Bestanden (>= " << grenze << "): " << bestanden << endl;
    cout << fixed << setprecision(2) << "Durchschnitt: " << schnitt << endl;
    cout << "Beste Punktzahl: " << punkte[best] << " (Nr " << best+1 << ")" << endl;
}

int main(int argc, const char* argv[]) {
    try {
        args_t args(argc, argv);
        string name = args.pos(0, "punkte.dat");
        int grenze = args.int_option("grenze", 50);
        if (grenze < 0 || grenze > 100) {
            throw runtime_error("Grenze muss zwischen 0 und 100 liegen");
        }
        bool verbose = args.flag("v");
        auswerten(lies_punkte(name), grenze, verbose);
    } catch (const exception& e) {
        cerr << "Fehler: " << e.what() << endl;
        return 1;
    }
    return 0;
}
