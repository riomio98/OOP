#include "alltest.h"
#include "messwerte.h"

#include <stdexcept>
#include <vector>

// Zusatz/Transfer zu Aufgabe 1: erst ins Projekt nehmen, wenn Teil b) dran ist

TEST(glaette, GleitenderMittelwert) {
    const std::vector<int> v{10, 20, 30, 40, 50};
    std::vector<int> g = glaette(v, 3);
    std::vector<int> erwartet{20, 30, 40};
    EXPECT_EQ(g, erwartet);
    EXPECT_EQ(v.size(), 5u); // Original unveraendert
    EXPECT_EQ(glaette(v, 5), std::vector<int>{30});
    EXPECT_EQ(glaette(v, 1), v);
}

TEST(glaette, Abschneiden) {
    std::vector<int> v{1, 2, 2, -3};
    std::vector<int> erwartet{1, 2, 0}; // ganzzahlige Division schneidet ab
    EXPECT_EQ(glaette(v, 2), erwartet);
}

TEST(glaette, Fehler) {
    std::vector<int> v{1, 2};
    EXPECT_THROW(glaette(v, 0), std::runtime_error);
    EXPECT_THROW(glaette(v, 3), std::runtime_error);
}

TEST(normiere, Feld) {
    int feld[]{215, 198, 240, 187};
    int offset = 0;
    normiere(feld, 4, offset);
    EXPECT_EQ(offset, 187);
    EXPECT_EQ(feld[0], 28);
    EXPECT_EQ(feld[3], 0);
    EXPECT_EQ(feld[2], 53);
    EXPECT_THROW(normiere(feld, 0, offset), std::runtime_error);
    EXPECT_THROW(normiere(nullptr, 3, offset), std::runtime_error);
}
