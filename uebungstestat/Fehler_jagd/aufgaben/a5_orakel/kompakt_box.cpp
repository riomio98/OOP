// Kompakt-Aufgabe: Schreiben Sie Box so kompakt wie moeglich (wenige Zeilen,
// Elementinitialisierungsliste), sodass main genau die angegebene Ausgabe hat.
#include <iostream>

using namespace std;

// ---- Ihr Code ----

// ------------------

void zeige(const Box& b) { cout << b.breite << "x" << b.hoehe << " "; }

int main() {
    Box a;
    Box b(3);
    Box c(3, 4);
    Box d = 7;
    zeige(a); zeige(b); zeige(c); zeige(d); zeige(5);
    cout << endl; // 1x1 3x3 3x4 7x7 5x5
}
