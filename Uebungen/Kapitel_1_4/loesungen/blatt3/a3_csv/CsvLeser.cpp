#include "CsvLeser.h"

#include <stdexcept>

using namespace std;

CsvLeser::CsvLeser(const string& dateiname, char trenner)
    : _datei(dateiname), _trenner(trenner), _zeile(0), _gelesen(0) {
    if (!_datei) {
        throw runtime_error("Datei nicht lesbar: " + dateiname);
    }
}

bool CsvLeser::naechste(vector<string>& felder) {
    string text;
    while (getline(_datei, text)) {
        ++_zeile;
        if (text.empty()) {
            continue; // leere Zeilen ueberspringen
        }
        felder.clear();
        string feld;
        for (char c : text) {
            if (c == _trenner) {
                felder.push_back(feld);
                feld.clear();
            } else {
                feld += c;
            }
        }
        felder.push_back(feld); // letztes Feld (auch wenn leer)
        ++_gelesen;
        return true;
    }
    return false;
}

size_t CsvLeser::zeile() const { return _zeile; }
size_t CsvLeser::gelesen() const { return _gelesen; }
char CsvLeser::trenner() const { return _trenner; }
