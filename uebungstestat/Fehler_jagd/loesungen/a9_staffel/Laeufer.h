#ifndef LAEUFER_H
#define LAEUFER_H

#include <string>

class Laeufer {
public:
    // zeit in Sekunden; leerer Name oder zeit < 0: std::runtime_error
    Laeufer(const std::string& name, int zeit = 0);

    const std::string& name() const;
    int zeit() const;
    bool setze_zeit(int zeit); // false und unveraendert bei zeit < 0
    std::string anzeige() const; // "Susi (1:05)"

private:
    std::string _name;
    int _zeit;
};

#endif
