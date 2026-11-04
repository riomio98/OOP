// Schreiben Sie Farbe so kompakt wie moeglich (struct erlaubt), sodass main die
// angegebene Ausgabe hat. 'r', 'g', 'b' stehen fuer reines Rot, Gruen, Blau
// (Anteil 255), jedes andere Zeichen fuer Schwarz.
#include <iostream>

using namespace std;

// ---- Loesung ----
struct Farbe {
    int r, g, b;
    Farbe(int w = 0) : Farbe(w, w, w) {}                    // Farbe(), Farbe(128), zeige(64)
    Farbe(int r, int g, int b = 0) : r(r), g(g), b(b) {}    // Farbe(1, 2)
    Farbe(char c) : Farbe(c == 'r' ? 255 : 0, c == 'g' ? 255 : 0, c == 'b' ? 255 : 0) {}
};
// Ohne Farbe(char) wuerde 'r' als int 114 zu Grau 114,114,114.
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
