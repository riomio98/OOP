#include "alltest.h"
#include "messwerte.h"

#include <stdexcept>
#include <vector>

TEST(begrenze, Normal) {
    std::vector<int> v{-50, 120, 300, 999, 75};
    int n = begrenze(v, 0, 300);
    EXPECT_EQ(n, 2);
    std::vector<int> erwartet{0, 120, 300, 300, 75};
    EXPECT_EQ(v, erwartet);
}

TEST(begrenze, NichtsZuTun) {
    std::vector<int> v{1, 2, 3};
    EXPECT_EQ(begrenze(v, 1, 3), 0);
    std::vector<int> leer;
    EXPECT_EQ(begrenze(leer, 0, 0), 0);
}

TEST(begrenze, UngueltigerBereich) {
    std::vector<int> v{1, 2, 3};
    try {
        begrenze(v, 5, 4);
        FAIL() << "begrenze(v, 5, 4) muss werfen";
    } catch (std::runtime_error& e) {
        EXPECT_STREQ(e.what(), "invalid range");
    }
    std::vector<int> unveraendert{1, 2, 3};
    EXPECT_EQ(v, unveraendert);
}

TEST(groesster, Veraendern) {
    std::vector<int> v{4, 17, -3, 17, 8};
    EXPECT_EQ(groesster(v), 17);
    groesster(v) = 0; // erstes Maximum wird 0
    std::vector<int> erwartet{4, 0, -3, 17, 8};
    EXPECT_EQ(v, erwartet);
    groesster(v) += 1;
    EXPECT_EQ(v[3], 18);
    EXPECT_EQ(&groesster(v), &v[3]);
}

TEST(groesster, Leer) {
    std::vector<int> v;
    try {
        groesster(v);
        FAIL() << "groesster bei leerem vector muss werfen";
    } catch (std::runtime_error& e) {
        EXPECT_STREQ(e.what(), "empty");
    }
}

TEST(kennzahlen, ConstVector) {
    const std::vector<int> v{215, 198, 240, 187};
    double mittel = 0.0;
    int spannweite = 0;
    kennzahlen(v, mittel, spannweite);
    EXPECT_DOUBLE_EQ(mittel, 210.0);
    EXPECT_EQ(spannweite, 53);
}

TEST(kennzahlen, EinWertUndLeer) {
    std::vector<int> v{-7};
    double mittel = 1.0;
    int spannweite = 1;
    kennzahlen(v, mittel, spannweite);
    EXPECT_DOUBLE_EQ(mittel, -7.0);
    EXPECT_EQ(spannweite, 0);
    std::vector<int> leer;
    EXPECT_THROW(kennzahlen(leer, mittel, spannweite), std::runtime_error);
}

TEST(entferne_ausreisser, Reihenfolge) {
    std::vector<int> v{12, 900, -15, -800, 801, 33, 800};
    EXPECT_EQ(entferne_ausreisser(v, 800), 2u);
    std::vector<int> erwartet{12, -15, -800, 33, 800};
    EXPECT_EQ(v, erwartet);
}

TEST(entferne_ausreisser, AlleNebeneinander) {
    std::vector<int> v{999, 999, 1, 999};
    EXPECT_EQ(entferne_ausreisser(v, 10), 3u);
    EXPECT_EQ(v.size(), 1u);
    EXPECT_EQ(v[0], 1);
    EXPECT_THROW(entferne_ausreisser(v, -1), std::runtime_error);
}
