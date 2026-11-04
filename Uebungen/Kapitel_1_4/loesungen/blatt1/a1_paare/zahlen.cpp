#include "zahlen.h"

#include <cstdlib>

namespace zt {

int ggt_rek(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    return b == 0 ? a : ggt_rek(b, a % b);
}

int ggt_it(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long kgv(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    long long g = ggt_it(a, b);
    return std::llabs(static_cast<long long>(a) / g * b);
}

bool teilerfremd(int a, int b) { return ggt_it(a, b) == 1; }

} // namespace zt
