#ifndef RINGPUFFER_H
#define RINGPUFFER_H

#include <cstddef>

class Ringpuffer {
public:
    explicit Ringpuffer(size_t kapazitaet);
    Ringpuffer(const Ringpuffer& other);
    Ringpuffer& operator=(const Ringpuffer& other);
    ~Ringpuffer();

    Ringpuffer& add(int wert);
    size_t size() const { return _size; }
    size_t capacity() const { return _cap; }
    bool empty() const { return _size == 0; }
    bool full() const { return _size == _cap; }
    int& at(size_t i);
    int at(size_t i) const;
    double mittel() const;
    void clear() { _start = 0; _size = 0; }
    int neuester() const;
    void resize(size_t neue_kapazitaet);

private:
    size_t _cap;
    size_t _start; // Index des aeltesten Werts
    size_t _size;
    int* _data;
};

#endif
