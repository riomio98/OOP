// Compiler-Orakel: Welche Zeilen in main uebersetzen nicht (und warum)?
// Was geben die uebrigen aus? Erst auf Papier, dann pruefen:
// fehlerhafte Zeile auskommentieren, neu bauen, naechsten Fehler lesen.
#include <iostream>
#include <string>

using namespace std;

int f(int a, int b = 2) { return a * b; }
int f(double) { return 10; }
int g(int& x) { return ++x; }
int h(const int& x) { return x + 1; }
string s(const string& t, char c = '!') { return t + c; }
void k(long) { cout << "long "; }
void k(double) { cout << "double "; }

int main() {
    int i = 3;
    const int ci = 4;
    long l = 5;
    cout << f(i) << endl;          // A
    cout << f(i, 3) << endl;       // B
    cout << f(2.5) << endl;        // C
    cout << f(2.5f) << endl;       // D
// cout << f(l) << endl;          // E  -> Fehler
    cout << g(i) << endl;          // F
// cout << g(ci) << endl;         // G  -> Fehler
// cout << g(5) << endl;          // H  -> Fehler
    cout << h(5) << endl;          // I
    cout << h(ci) << " " << i << endl; // J
    cout << s("Hi") << endl;       // K
    cout << s("Hi", '?') << endl;  // L
// cout << s("Hi", "?") << endl;  // M  -> Fehler
    k(1L);                         // N
// k(1);                          // O  -> Fehler
    k(1.0f);                       // P
// k('a');                        // Q  -> Fehler
    cout << endl;
}
