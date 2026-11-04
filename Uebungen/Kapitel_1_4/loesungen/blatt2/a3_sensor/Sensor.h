#ifndef SENSOR_H
#define SENSOR_H

class Sensor {
public:
    explicit Sensor(double messwert = 0.0);
    Sensor(const Sensor& other);            // neue Kennung, gleicher Messwert
    Sensor& operator=(const Sensor& other); // Kennung bleibt, Messwert wird uebernommen
    ~Sensor();

    int kennung() const;
    double messwert() const;
    void messe(double wert);

    static int aktive();
    static int hoechststand();

    friend void tausche_messwerte(Sensor& a, Sensor& b);

private:
    const int _kennung;
    double _messwert;
    static int _naechste;
    static int _aktive;
    static int _hoechststand;
    static int neue_kennung(); // zaehlt aktive und Hoechststand mit
};

void tausche_messwerte(Sensor& a, Sensor& b);

#endif
