// Loesung: Dreierregel mit Copy & Swap ergaenzt.
#include <cstddef>
#include <iostream>
#include <utility>

using namespace std;

class Puffer {
public:
    explicit Puffer(size_t n) : _n(n), _p(new int[n]{}) { cout << "K" << _n << " "; }
    ~Puffer() {
        cout << "D" << _n << " " << flush;
        delete[] _p;
    }
    Puffer(const Puffer& o) : _n(o._n), _p(new int[o._n]) {
        for (size_t i = 0; i < _n; ++i) _p[i] = o._p[i];
        cout << "C" << _n << " ";
    }
    Puffer& operator=(Puffer o) { // Kopie im Parameter
        std::swap(_n, o._n);
        std::swap(_p, o._p);
        return *this;             // o stirbt mit dem alten Speicher von *this
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
