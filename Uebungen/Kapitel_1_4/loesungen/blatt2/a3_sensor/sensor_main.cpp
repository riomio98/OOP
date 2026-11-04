// Verfolgung: eigenes Projekt (ohne Tests) mit Sensor.h/.cpp.
#include <iostream>
#include <vector>

#include "Sensor.h"

using namespace std;

void zeige(const char* wo) {
    cout << wo << ": aktive " << Sensor::aktive() << ", hoechststand " << Sensor::hoechststand()
         << endl;
}

int main() {
    zeige("Start");
    {
        vector<Sensor> v;
        for (int i = 0; i < 3; ++i) {
            v.push_back(Sensor(i * 1.5));
            zeige("nach push_back");
        }
        cout << "Kennungen im vector:";
        for (const Sensor& s : v) cout << " " << s.kennung();
        cout << endl;
    }
    zeige("nach Block 1");
    {
        vector<Sensor> v;
        v.reserve(3);
        for (int i = 0; i < 3; ++i) {
            v.push_back(Sensor(i * 1.5));
        }
        zeige("Block 2 mit reserve");
    }
    zeige("Ende");
}
