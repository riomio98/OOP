/*
 * messwerte.h
 *
 *  Created on: 01.11.2026
 *      Author: n3034770
 */

#ifndef MESSWERTE_H_
#define MESSWERTE_H_

#include <vector>

size_t begrenze(std::vector<int>& v, int min, int max);
int& groesster(std::vector<int>& v);
void kennzahlen(const std::vector<int>& v, double& mean, int& range);
size_t entferne_ausreisser(std::vector<int>& v, int limit);

#endif /* MESSWERTE_H_ */
