// Schreiben Sie Zaehlwerk mit class, so wenigen Methoden wie moeglich und
// Elementinitialisierungsliste. tick() erhoeht den Stand des Objekts um 1;
// ticks() zaehlt alle tick-Aufrufe aller Zaehlwerke.
#include <iostream>

using namespace std;

// ---- Ihr Code ----

// ------------------

int main() {
    Zaehlwerk a, b(10);
    const Zaehlwerk c(5);
    a.tick().tick();
    b.tick();
    cout << a.stand() << " " << b.stand() << " " << c.stand() << " "
         << Zaehlwerk::ticks() << endl; // 2 11 5 3
    // c.tick();        // muss einen Compilerfehler geben
    // Zaehlwerk d = 7; // muss einen Compilerfehler geben
}
