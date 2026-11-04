#ifndef ZEILENPUFFER_H
#define ZEILENPUFFER_H

#include <cstddef>
#include <string>

// Zeilen in einem selbst verwalteten Feld std::string* (kein vector).
class Zeilenpuffer {
public:
    explicit Zeilenpuffer(std::size_t kapazitaet = 2); // 0: runtime_error("invalid capacity")
    Zeilenpuffer(const Zeilenpuffer& other);
    Zeilenpuffer& operator=(const Zeilenpuffer& other); // klassisch
    ~Zeilenpuffer();

    std::size_t size() const;
    std::size_t kapazitaet() const;
    void anhaengen(const std::string& zeile);           // voll: Kapazitaet verdoppeln
    std::string& zeile(std::size_t i);                  // runtime_error("index out of range")
    const std::string& zeile(std::size_t i) const;
    void entferne(std::size_t i);                       // runtime_error("index out of range")
    std::size_t finde(const std::string& wort, std::size_t ab = 0) const; // nicht gefunden: size()

private:
    std::string* _zeilen;
    std::size_t _size;
    std::size_t _cap;
};

#endif
