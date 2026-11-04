#include <type_traits>

#include "gtest/gtest.h"
#include "Sensor.h"

static_assert(!std::is_convertible<double, Sensor>::value,
              "Ein Messwert darf nicht unbemerkt zu einem Sensor werden");

TEST(Sensor, Kennungen) {
    const Sensor a;
    const Sensor b(21.5);
    EXPECT_EQ(b.kennung(), a.kennung() + 1);
    EXPECT_DOUBLE_EQ(a.messwert(), 0.0);
    EXPECT_DOUBLE_EQ(b.messwert(), 21.5);
}

TEST(Sensor, Aktive) {
    int vorher = Sensor::aktive();
    {
        Sensor a, b, c;
        EXPECT_EQ(Sensor::aktive(), vorher + 3);
    }
    EXPECT_EQ(Sensor::aktive(), vorher);
}

TEST(Sensor, Hoechststand) {
    int vorher = Sensor::aktive();
    int hs = Sensor::hoechststand();
    {
        Sensor a, b, c, d, e, f, g, h, i, j; // 10 gleichzeitig
    }
    EXPECT_GE(Sensor::hoechststand(), vorher + 10);
    EXPECT_GE(Sensor::hoechststand(), hs);
    int jetzt = Sensor::hoechststand();
    { Sensor k; }
    EXPECT_EQ(Sensor::hoechststand(), jetzt); // sinkt nie
}

TEST(Sensor, Kopie) {
    Sensor a(3.5);
    int vorher = Sensor::aktive();
    Sensor b(a);
    EXPECT_NE(b.kennung(), a.kennung());
    EXPECT_GT(b.kennung(), a.kennung());
    EXPECT_DOUBLE_EQ(b.messwert(), 3.5);
    EXPECT_EQ(Sensor::aktive(), vorher + 1);
}

TEST(Sensor, Zuweisung) {
    Sensor a(1.0), b(2.0);
    int kb = b.kennung();
    b = a;
    EXPECT_EQ(b.kennung(), kb);
    EXPECT_DOUBLE_EQ(b.messwert(), 1.0);
    a.messe(9.0);
    EXPECT_DOUBLE_EQ(b.messwert(), 1.0);
}

TEST(Sensor, Tauschen) {
    Sensor a(1.0), b(2.0);
    tausche_messwerte(a, b);
    EXPECT_DOUBLE_EQ(a.messwert(), 2.0);
    EXPECT_DOUBLE_EQ(b.messwert(), 1.0);
}
