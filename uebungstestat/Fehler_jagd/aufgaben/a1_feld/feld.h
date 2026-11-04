#ifndef FELD_H
#define FELD_H

#include <cstddef>
#include <vector>

// Ermittelt Minimum und Maximum. Leerer Vektor: std::runtime_error("empty"),
// mn und mx bleiben dann unveraendert.
void grenzen(const std::vector<int>& v, int& mn, int& mx);

// Liefert das groesste Element so, dass der Aufrufer es im Vektor aendern kann.
// Bei mehreren gleich grossen gilt das erste. Leer: std::runtime_error("empty").
int& groesstes(std::vector<int>& v);

// Entfernt alle Vorkommen von wert, liefert die Anzahl entfernter Elemente.
std::size_t entferne(std::vector<int>& v, int wert);

// Vertauscht zwei int-Zeiger (nicht die Werte, auf die sie zeigen).
void tausche(int*& a, int*& b);

#endif
