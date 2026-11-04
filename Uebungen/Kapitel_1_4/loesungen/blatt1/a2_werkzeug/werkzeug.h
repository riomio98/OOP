#ifndef WERKZEUG_H
#define WERKZEUG_H

#include <cstddef>
#include <string>

namespace wz {

void sortiere3(int& a, int& b, int& c);
int& element(int* feld, std::size_t len, long idx);
bool teile(int dividend, int divisor, int& quotient, int& rest);
std::size_t zaehle(const std::string& text, char c = ' ');
std::string wiederhole(const std::string& s, int n = 2, const std::string& trenner = "");

} // namespace wz

#endif
