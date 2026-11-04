#include "werkzeug.h"

#include <stdexcept>
#include <utility>

namespace wz {

void sortiere3(int& a, int& b, int& c) {
    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);
    if (a > b) std::swap(a, b);
}

int& element(int* feld, std::size_t len, long idx) {
    long n = static_cast<long>(len);
    if (idx < 0) {
        idx += n; // -1 ist das letzte Element
    }
    if (idx < 0 || idx >= n) {
        throw std::runtime_error("index out of range");
    }
    return feld[idx];
}

bool teile(int dividend, int divisor, int& quotient, int& rest) {
    if (divisor == 0) {
        return false; // Ausgabeparameter bleiben unveraendert
    }
    quotient = dividend / divisor;
    rest = dividend % divisor;
    return true;
}

std::size_t zaehle(const std::string& text, char c) {
    std::size_t n = 0;
    for (char x : text) {
        if (x == c) ++n;
    }
    return n;
}

std::string wiederhole(const std::string& s, int n, const std::string& trenner) {
    if (n < 0) {
        throw std::runtime_error("negative count");
    }
    std::string ergebnis;
    for (int i = 0; i < n; ++i) {
        if (i > 0) ergebnis += trenner;
        ergebnis += s;
    }
    return ergebnis;
}

} // namespace wz
