#ifndef ZAHLENFOLGE_H
#define ZAHLENFOLGE_H

#include <cstddef>

// Folge von int-Werten in einem selbst verwalteten Freispeicher-Feld.
// append haengt an; ist das Feld voll, wird die Kapazitaet verdoppelt.
class Zahlenfolge {
public:
    explicit Zahlenfolge(std::size_t kapazitaet = 4); // 0: runtime_error("invalid capacity")
    Zahlenfolge(const Zahlenfolge& other);
    Zahlenfolge& operator=(const Zahlenfolge& other);
    ~Zahlenfolge();

    std::size_t size() const;
    std::size_t capacity() const;
    void append(int wert);
    int& at(std::size_t i);       // ungueltig: runtime_error("index out of range")
    int at(std::size_t i) const;  // ungueltig: runtime_error("index out of range")
    long summe() const;

private:
    int* _daten;
    std::size_t _size;
    std::size_t _cap;
};

#endif
