// Programm notenliste: liest name;punkte aus einer CSV-Datei und gibt eine Liste aus.
// Aufruf: notenliste [datei] [-trenner=,]
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "CsvLeser.h"
#include "pbma.h"

using namespace std;

int main(int argc, const char* argv[]) {
    try {
        args_t args(argc, argv);
        string trenner = args.option("trenner", ";");
        if (trenner.size() != 1) {
            throw runtime_error("Trenner muss genau ein Zeichen sein");
        }
        CsvLeser leser(args.pos(0, "noten.csv"), trenner[0]);
        vector<string> f;
        int summe = 0;
        while (leser.naechste(f)) {
            if (f.size() != 2) {
                cerr << "Zeile " << leser.zeile() << " uebersprungen" << endl;
                continue;
            }
            int punkte = stoi(f[1]);
            summe += punkte;
            cout << left << setw(10) << f[0] << right << setw(4) << punkte << endl;
        }
        cout << "Datensaetze: " << leser.gelesen() << ", Summe: " << summe << endl;
    } catch (const exception& e) {
        cerr << "Fehler: " << e.what() << endl;
        return 1;
    }
    return 0;
}
