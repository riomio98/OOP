// Debugger-Aufgabe Speicherlayout (wie Blatt 1, Aufgabe 4, und Skript Abb. 2.1).
// 1. Fragen F1-F8 auf Papier beantworten (64 Bit, 8-Byte-Alignment fuer double).
// 2. Breakpoint auf die Zeile mit "HIER", Debug starten.
// 3. Antworten im Expressions-View pruefen (Ausdruecke stehen bei den Fragen).
// 4. Erst danach das Programm bis zum Ende laufen lassen und vergleichen.
#include <iostream>

using namespace std;

struct Messpunkt {
    char kennung;
    double x;
    int nr;
    short werte[3];
};

int main() {
    Messpunkt feld[5];
    for (int i = 0; i < 5; ++i) {
        feld[i].kennung = static_cast<char>('A' + i);
        feld[i].x = i * 0.5;
        feld[i].nr = 100 + i;
        for (int k = 0; k < 3; ++k) {
            feld[i].werte[k] = static_cast<short>(10 * i + k);
        }
    }
    const Messpunkt* p1 = &feld[1];
    const Messpunkt* p4 = &feld[4];

    int (*m)[4] = new int[3][4]{}; // 3 Zeilen, 4 Spalten, alles 0
    int* flach = &m[0][0];
    flach[6] = 42;

    cout << "HIER" << endl; // <- Breakpoint
    cout << "F1 " << sizeof(Messpunkt) << endl;                                   // sizeof(Messpunkt)
    cout << "F2 " << (reinterpret_cast<const char*>(&feld[0].nr) -
                      reinterpret_cast<const char*>(&feld[0])) << endl;          // (char*)&feld[0].nr - (char*)&feld[0]
    cout << "F3 " << (p4 - p1) << endl;                                           // p4 - p1
    cout << "F4 " << (reinterpret_cast<const char*>(p4) -
                      reinterpret_cast<const char*>(p1)) << endl;                // (char*)p4 - (char*)p1
    cout << "F5 " << (&feld[3].werte[2] - &feld[1].werte[0]) << endl;            // &feld[3].werte[2] - &feld[1].werte[0]
    cout << "F6 " << (p1 + 2)->nr << " " << (p1 + 2)->werte[1] << endl;          // (p1+2)->nr, (p1+2)->werte[1]
    cout << "F7 " << m[1][2] << " " << (&m[2][1] - &m[0][0]) << endl;            // m[1][2], &m[2][1] - &m[0][0]
    cout << "F8 " << sizeof(m[0]) << " " << sizeof(m) << endl;                    // sizeof(m[0]), sizeof(m)

    delete[] m;
}
