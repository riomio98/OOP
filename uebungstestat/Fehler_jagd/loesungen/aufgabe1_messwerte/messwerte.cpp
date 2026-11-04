#include "messwerte.h"

#include <stdexcept>

int begrenze(std::vector<int>& werte, int min, int max) {
    if (min > max) {
        throw std::runtime_error("invalid range");
    }
    int geaendert{0};
    for (int& w : werte) {
        if (w < min) {
            w = min;
            geaendert += 1;
        } else if (w > max) {
            w = max;
            geaendert += 1;
        }
    }
    return geaendert;
}

int& groesster(std::vector<int>& werte) {
    if (werte.empty()) {
        throw std::runtime_error("empty");
    }
    size_t idx{0};
    for (size_t i = 1; i < werte.size(); ++i) {
        if (werte[i] > werte[idx]) {
            idx = i;
        }
    }
    return werte[idx];
}

void kennzahlen(const std::vector<int>& werte, double& mittel, int& spannweite) {
    if (werte.empty()) {
        throw std::runtime_error("empty");
    }
    long summe{0};
    int min{werte[0]};
    int max{werte[0]};
    for (int w : werte) {
        summe += w;
        min = w < min ? w : min;
        max = w > max ? w : max;
    }
    mittel = static_cast<double>(summe) / static_cast<double>(werte.size());
    spannweite = max - min;
}

size_t entferne_ausreisser(std::vector<int>& werte, int grenze) {
    if (grenze < 0) {
        throw std::runtime_error("invalid limit");
    }
    size_t entfernt{0};
    size_t i{0};
    while (i < werte.size()) {
        if (werte[i] > grenze or werte[i] < -grenze) {
            werte.erase(begin(werte) + static_cast<long>(i));
            entfernt += 1;
        } else {
            i += 1;
        }
    }
    return entfernt;
}

std::vector<int> glaette(const std::vector<int>& werte, size_t fenster) {
    if (fenster == 0 or fenster > werte.size()) {
        throw std::runtime_error("invalid window");
    }
    std::vector<int> ergebnis;
    for (size_t i = 0; i + fenster <= werte.size(); ++i) {
        long summe{0};
        for (size_t k = 0; k < fenster; ++k) {
            summe += werte[i + k];
        }
        ergebnis.push_back(static_cast<int>(summe / static_cast<long>(fenster)));
    }
    return ergebnis;
}

void normiere(int* werte, size_t n, int& offset) {
    if (werte == nullptr or n == 0) {
        throw std::runtime_error("empty");
    }
    offset = werte[0];
    for (size_t i = 1; i < n; ++i) {
        offset = werte[i] < offset ? werte[i] : offset;
    }
    for (size_t i = 0; i < n; ++i) {
        werte[i] -= offset;
    }
}
