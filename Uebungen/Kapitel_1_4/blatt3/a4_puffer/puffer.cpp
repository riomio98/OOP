// Papieraufgabe (Speicherbild wie Skript Abb. 4.1). Erst auf Papier, dann pruefen.
#include <cstddef>
#include <iostream>

using namespace std;

class Puffer {
public:
    explicit Puffer(size_t n) : _n(n), _p(new int[n]{}) { cout << "K" << _n << " "; }
    ~Puffer() {
        cout << "D" << _n << " " << flush;
        delete[] _p;
    }
    int& at(size_t i) { return _p[i]; }
    size_t _n;
    int* _p;
};

int main() {
    Puffer a(3);                             // 1
    Puffer b(5);                             // 2
    a.at(0) = 7;                             // 3
    Puffer c = a;                            // 4
    c.at(0) = 9;                             // 5
    b = a;                                   // 6
    cout << a.at(0) << " " << b._n << endl;  // 7
}                                            // 8
