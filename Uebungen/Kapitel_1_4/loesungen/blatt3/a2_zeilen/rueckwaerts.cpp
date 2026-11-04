// Programm rueckwaerts: gibt die Zeilen einer Datei in umgekehrter Reihenfolge aus.
// Aufruf: rueckwaerts [datei] [-leer] [-suche=Wort]
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

#include "Zeilenpuffer.h"
#include "pbma.h"

using namespace std;

int main(int argc, const char* argv[]) {
    try {
        args_t args(argc, argv);
        string name = args.pos(0, "gedicht.txt");
        ifstream datei(name);
        if (!datei) {
            throw runtime_error("Datei nicht lesbar: " + name);
        }
        Zeilenpuffer puffer;
        string zeile;
        while (getline(datei, zeile)) {
            puffer.anhaengen(zeile);
        }
        bool leer = args.flag("leer");
        string suche = args.option("suche", "");
        size_t ausgegeben = 0;
        for (size_t k = puffer.size(); k > 0; --k) { // rueckwaerts ohne size_t-Unterlauf
            const string& z = puffer.zeile(k - 1);
            if (z.empty() && !leer) continue;
            if (!suche.empty() && z.find(suche) == string::npos) continue;
            cout << setw(3) << k << ": " << z << endl;
            ++ausgegeben;
        }
        cout << ausgegeben << " von " << puffer.size() << " Zeilen" << endl;
    } catch (const exception& e) {
        cerr << "Fehler: " << e.what() << endl;
        return 1;
    }
    return 0;
}
