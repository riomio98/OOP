// Schreiben Sie Farbe so kompakt wie moeglich (struct erlaubt), sodass main die
// angegebene Ausgabe hat. 'r', 'g', 'b' stehen fuer reines Rot, Gruen, Blau
// (Anteil 255), jedes andere Zeichen fuer Schwarz.
#include <iostream>

using namespace std;

// ---- Ihr Code ----

// ------------------

void zeige(const Farbe& f) { cout << f.r << "," << f.g << "," << f.b << " "; }

int main() {
    Farbe schwarz;
    Farbe grau(128);
    Farbe lila(128, 0, 128);
    Farbe rot = 'r';
    zeige(schwarz); zeige(grau); zeige(lila); zeige(rot);
    zeige('b'); zeige(Farbe(1, 2)); zeige(64); zeige('x');
    cout << endl;
    // 0,0,0 128,128,128 128,0,128 255,0,0 0,0,255 1,2,0 64,64,64 0,0,0
}
