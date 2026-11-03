#ifndef FAHRRAD_H
#define FAHRRAD_H

#include <string>

class Fahrrad {
public:
    Fahrrad(const std::string& modell, int km = 0);
    ~Fahrrad();
    Fahrrad(const Fahrrad&) = delete;
    Fahrrad& operator=(const Fahrrad&) = delete;

    int nummer() const { return _nummer; }
    const std::string& modell() const { return _modell; }
    int km() const { return _km; }
    bool ausgeliehen() const { return _ausgeliehen; }

    bool ausleihen();
    bool zurueckgeben(int gefahren);
    bool braucht_wartung(int intervall = 500) const;
    bool warten();

    static int unterwegs() { return _unterwegs; }

    friend bool tausche_modell(Fahrrad& a, Fahrrad& b);

private:
    const int _nummer;
    std::string _modell;
    int _km;
    int _seit_wartung{0};
    bool _ausgeliehen{false};
    static int _naechste_nummer;
    static int _unterwegs;
};

bool tausche_modell(Fahrrad& a, Fahrrad& b);

#endif
