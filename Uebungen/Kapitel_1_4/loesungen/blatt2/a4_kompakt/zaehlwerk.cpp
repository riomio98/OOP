// Schreiben Sie Zaehlwerk mit class, so wenigen Methoden wie moeglich und
// Elementinitialisierungsliste. tick() erhoeht den Stand des Objekts um 1;
// ticks() zaehlt alle tick-Aufrufe aller Zaehlwerke.
#include <iostream>

using namespace std;

// ---- Loesung ----
class Zaehlwerk {
public:
    explicit Zaehlwerk(int start = 0) : _stand(start) {}   // explicit: Zaehlwerk d = 7; scheitert
    Zaehlwerk& tick() { ++_stand; ++_ticks; return *this; } // Referenz fuer a.tick().tick()
    int stand() const { return _stand; }                    // const: c.stand() geht
    static int ticks() { return _ticks; }
private:
    int _stand;
    static int _ticks;
};
int Zaehlwerk::_ticks = 0;
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
