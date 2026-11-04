// Kompakt-Aufgabe: Schreiben Sie Zahl mit dem Schluesselwort class, so wenigen
// Methoden wie moeglich und Elementinitialisierungsliste.
#include <iostream>

using namespace std;

// ---- Loesung ----
class Zahl {
public:
    Zahl(int w = 0) : _w(w) {}
    int& wert() { return _w; }             // fuer veraenderbare Objekte
    int wert() const { return _w; }        // fuer const Objekte (cz)
private:
    int _w;
};
// ------------------

int main() {
    Zahl z;
    const Zahl cz(5);
    Zahl feld[2];
    z.wert() = 8;
    feld[1].wert() += 2;
    cout << z.wert() << " " << cz.wert() << " " << feld[0].wert() << " "
         << feld[1].wert() << endl; // 8 5 0 2
    // cz.wert() = 1;  // muss einen Compilerfehler geben
}
