#ifndef BITMENGE_H
#define BITMENGE_H

#include <cstddef>
#include <iostream>

// Menge von n Bits, intern in (n + 7) / 8 Bytes im Freispeicher.
class Bitmenge {
public:
    explicit Bitmenge(std::size_t n);             // n == 0: runtime_error("invalid size")
    Bitmenge(const Bitmenge& other);
    Bitmenge& operator=(Bitmenge other);          // Copy & Swap
    ~Bitmenge();
    friend void swap(Bitmenge& a, Bitmenge& b) noexcept;

    std::size_t groesse() const;
    void setze(std::size_t i);                    // runtime_error("index out of range")
    void loesche(std::size_t i);
    bool ist_gesetzt(std::size_t i) const;
    std::size_t anzahl() const;                   // Anzahl gesetzter Bits
    Bitmenge& vereinige(const Bitmenge& other);   // runtime_error("size mismatch")
    void out(std::ostream& os = std::cout) const; // z. B. 0100110

private:
    unsigned char* _bytes;
    std::size_t _n;
    std::size_t bytes() const;
    void pruefe(std::size_t i) const;
};

#endif
