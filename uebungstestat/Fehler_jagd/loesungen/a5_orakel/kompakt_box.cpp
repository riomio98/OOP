// Kompakt-Aufgabe: Schreiben Sie Box so kompakt wie moeglich (wenige Zeilen,
// Elementinitialisierungsliste), sodass main genau die angegebene Ausgabe hat.
#include <iostream>

using namespace std;

// ---- Loesung ----
struct Box {
    int breite, hoehe;
    Box(int b = 1) : Box(b, b) {}             // delegiert, deckt Box() und Box(3) ab
    Box(int b, int h) : breite(b), hoehe(h) {}
};
// Alternative mit einem Konstruktor:
//   Box(int b = 1, int h = 0) : breite(b), hoehe(h ? h : b) {}
// Mit explicit vor Box(int b = 1) uebersetzen  Box d = 7;  und  zeige(5);  nicht mehr.
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
