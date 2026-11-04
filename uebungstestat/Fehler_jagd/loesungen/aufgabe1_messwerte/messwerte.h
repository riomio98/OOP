#ifndef MESSWERTE_H
#define MESSWERTE_H

#include <cstddef>
#include <vector>

int begrenze(std::vector<int>& werte, int min, int max);
int& groesster(std::vector<int>& werte);
void kennzahlen(const std::vector<int>& werte, double& mittel, int& spannweite);
size_t entferne_ausreisser(std::vector<int>& werte, int grenze);
std::vector<int> glaette(const std::vector<int>& werte, size_t fenster);
void normiere(int* werte, size_t n, int& offset);

#endif
