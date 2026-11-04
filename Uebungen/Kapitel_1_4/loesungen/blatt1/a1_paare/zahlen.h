#ifndef ZAHLEN_H
#define ZAHLEN_H

namespace zt {

int ggt_rek(int a, int b);        // rekursiv, Ergebnis >= 0
int ggt_it(int a, int b);         // iterativ, Ergebnis >= 0
long long kgv(int a, int b);      // 0, falls a oder b 0 ist
bool teilerfremd(int a, int b);   // ggT == 1

} // namespace zt

#endif
