#ifndef CSVLESER_H
#define CSVLESER_H

#include <cstddef>
#include <fstream>
#include <string>
#include <vector>

// Liest eine Textdatei Datensatz fuer Datensatz; Felder durch ein Trennzeichen getrennt.
class CsvLeser {
public:
    explicit CsvLeser(const std::string& dateiname, char trenner = ';');
    CsvLeser(const CsvLeser&) = delete;
    CsvLeser& operator=(const CsvLeser&) = delete;
    // Kein eigener Destruktor noetig: _datei (ifstream) schliesst sich selbst (RAII).

    bool naechste(std::vector<std::string>& felder); // false am Dateiende, felder dann unveraendert
    std::size_t zeile() const;   // Zeilennummer (ab 1) des zuletzt gelieferten Datensatzes
    std::size_t gelesen() const; // Anzahl gelieferter Datensaetze
    char trenner() const;

private:
    std::ifstream _datei;
    const char _trenner;
    std::size_t _zeile;
    std::size_t _gelesen;
};

#endif
