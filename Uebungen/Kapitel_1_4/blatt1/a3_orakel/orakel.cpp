// Uebersetzt es korrekt? Wenn nicht, welche Zeilen sind fehlerhaft?
// Gehen Sie davon aus, dass jede fehlerhafte Zeile einfach fehlt.
// Was gibt das Programm dann aus?
#include <iostream>
#include <string>

namespace a {
int wert = 1;
int f(int x) { return x + 10; }
} // namespace a

namespace b {
int wert = 2;
int f(double x) { return static_cast<int>(x) + 20; }
} // namespace b

int wert = 3;

void p(int* q) { std::cout << "int* "; *q += 1; }
void p(const int* q) { std::cout << "const int* " << *q << " "; }
int m(int x, int y = 4, int z = 5) { return x * 100 + y * 10 + z; }
int& groesser(int& x, int& y) { return x > y ? x : y; }

using namespace std;

int main() {
    int i = 7, j = 9;
    const int k = 8;
    int* const pc = &i;
    const int* cp = &i;
    cout << a::wert + b::wert + ::wert << endl;   // A
    cout << wert << endl;                         // B
    { using namespace a; cout << f(1) << endl; }  // C
    { using namespace a; using namespace b;
      cout << f(1.5) << " " << f(1) << endl; }    // D
    { using namespace a; using namespace b;
      cout << wert << endl; }                     // E
    *pc = 11;                                     // F
    pc = &j;                                      // G
    *cp = 12;                                     // H
    cp = &k;                                      // I
    p(&i); p(&k); p(cp); cout << i << endl;       // J
    cout << m(1) << " " << m(1, 2) << " " << m(1, 2, 3) << endl; // K
    cout << m() << endl;                          // L
    groesser(i, j) = 0; cout << i << " " << j << endl;           // M
    groesser(i, 5) = 1;                           // N
    string s = "OOP"; string& r = s; r += "!"; cout << s << endl; // O
    int& kein;                                    // P
}
