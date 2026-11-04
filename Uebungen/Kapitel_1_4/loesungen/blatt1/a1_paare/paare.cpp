// Programm paare: ggT/kgV benachbarter Zahlenpaare einer Datei.
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "pbma.h"
#include "zahlen.h"

using namespace std;

int main(int argc, const char* argv[]) {
    try {
        args_t args(argc, argv);
        string name = args.pos(0, "paare.dat");
        vector<int> z = read_ints(name);
        if (z.empty() || z.size() % 2 != 0) {
            throw runtime_error("ungerade Anzahl von Zahlen in " + name);
        }
        long long summe = 0;
        int fremd = 0;
        for (size_t i = 0; i < z.size(); i += 2) {
            int g = zt::ggt_it(z[i], z[i + 1]);
            if (g != zt::ggt_rek(z[i], z[i + 1])) {
                throw runtime_error("ggt_it und ggt_rek unterschiedlich");
            }
            long long k = zt::kgv(z[i], z[i + 1]);
            summe += k;
            if (g == 1) {
                ++fremd;
            }
            if (args.flag("v")) {
                cout << setw(8) << z[i] << setw(8) << z[i + 1] << ": ggT " << g
                     << ", kgV " << k << endl;
            }
        }
        cout << "Paare: " << z.size() / 2 << endl;
        cout << "Teilerfremd: " << fremd << endl;
        cout << "Summe kgV: " << summe << endl;
        if (args.flag("zeit")) {
            vector<int> viele = create_same_randints(2000000, 1, 1000000);
            long long s1 = 0, s2 = 0;
            Timer t1;
            for (size_t i = 0; i + 1 < viele.size(); i += 2) s1 += zt::ggt_rek(viele[i], viele[i + 1]);
            cout << "rekursiv: " << t1.human_measure() << endl;
            Timer t2;
            for (size_t i = 0; i + 1 < viele.size(); i += 2) s2 += zt::ggt_it(viele[i], viele[i + 1]);
            cout << "iterativ: " << t2.human_measure() << endl;
            if (s1 != s2) {
                throw runtime_error("Summen verschieden");
            }
        }
    } catch (const exception& e) {
        cerr << "Fehler: " << e.what() << endl;
        return 1;
    }
    return 0;
}
