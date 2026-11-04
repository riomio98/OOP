// Stufe 3: eigenes Projekt staffel (ohne Tests), Laeufer.* und Team.* hineinkopieren.
// Aufruf: staffel [-v] Name1 Name2 ...
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Laeufer.h"
#include "Team.h"
#include "pbma.h"

using namespace std;

int main(int argc, const char* argv[]) {
    try {
        args_t args(argc, argv);
        size_t n = args.len_pos();
        if (n == 0) {
            throw runtime_error("keine Laeufer angegeben");
        }
        vector<int> zeiten = create_same_randints(static_cast<int>(n), 40, 90);
        vector<Team> teams;
        for (size_t i = 0; i < n; ++i) {
            if (i % Team::MAX == 0) {
                teams.push_back(Team("Team " + to_string(teams.size() + 1)));
            }
            teams.back().aufnehmen(Laeufer(args.pos(i), zeiten[i]));
        }
        size_t sieger = 0;
        for (size_t t = 0; t < teams.size(); ++t) {
            const Team& team = teams[t];
            cout << team.name() << ": " << team.gesamtzeit() << " s" << endl;
            if (args.flag("v")) {
                for (size_t i = 0; i < team.groesse(); ++i) {
                    cout << "  " << team.laeufer(i).anzeige() << endl;
                }
            }
            if (team.groesse() == Team::MAX &&
                (teams[sieger].groesse() < Team::MAX ||
                 team.gesamtzeit() < teams[sieger].gesamtzeit())) {
                sieger = t;
            }
        }
        if (teams[sieger].groesse() < Team::MAX) {
            cout << "Kein vollstaendiges Team" << endl;
        } else {
            cout << "Sieger: " << teams[sieger].name() << ", schnellster Laeufer: "
                 << teams[sieger].schnellster().anzeige() << endl;
        }
    } catch (const exception& e) {
        cerr << "Fehler: " << e.what() << endl;
        return 1;
    }
    return 0;
}
