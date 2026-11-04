// Debugger-Aufgabe: erst auf Papier vorhersagen, dann pruefen.
// Eigenes Konsolenprojekt (nicht ins Testprojekt!).
#include <iostream>
#include <string>

using namespace std;

class Laut {
public:
    Laut(const string& name = "?") : _name(name) { cout << "K(" << _name << ") "; }
    Laut(const Laut& o) : _name(o._name + "'") { cout << "C(" << _name << ") "; }
    Laut& operator=(const Laut& o) {
        cout << "Z(" << _name << "=" << o._name << ") ";
        _name = o._name;
        return *this;
    }
    ~Laut() { cout << "D(" << _name << ") "; }

private:
    string _name;
};

void per_wert(Laut) { cout << "| "; }
void per_ref(const Laut&) { cout << "| "; }
Laut fabrik() { return Laut("f"); }

int main() {
    cout << "1: "; { Laut a("a"); }                           cout << endl;
    cout << "2: "; { Laut a("a"); per_wert(a); }              cout << endl;
    cout << "3: "; { Laut a("a"); per_ref(a); }               cout << endl;
    cout << "4: "; { Laut a("a"); Laut b = a; }               cout << endl;
    cout << "5: "; { Laut a("a"); Laut b("b"); b = a; }       cout << endl;
    cout << "6: "; { Laut feld[2]; }                          cout << endl;
    cout << "7: "; { Laut x = fabrik(); }                     cout << endl;
    cout << "8: "; { per_ref(Laut("t")); cout << "nach "; }   cout << endl;
    cout << "9: "; { Laut* p = new Laut("p"); delete p; }     cout << endl;
}
