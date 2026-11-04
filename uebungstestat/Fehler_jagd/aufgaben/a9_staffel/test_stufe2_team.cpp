#include <stdexcept>

#include "gtest/gtest.h"
#include "Laeufer.h"
#include "Team.h"

using namespace std;

TEST(Team, Aufnehmen) {
    Team t("Blau");
    EXPECT_EQ(t.name(), "Blau");
    EXPECT_EQ(t.groesse(), 0u);
    EXPECT_TRUE(t.aufnehmen(Laeufer("A", 60)));
    EXPECT_TRUE(t.aufnehmen(Laeufer("B", 55)));
    EXPECT_TRUE(t.aufnehmen(Laeufer("C", 70)));
    EXPECT_TRUE(t.aufnehmen(Laeufer("D", 55)));
    EXPECT_FALSE(t.aufnehmen(Laeufer("E", 40))); // hoechstens 4
    EXPECT_EQ(t.groesse(), 4u);
    EXPECT_EQ(t.gesamtzeit(), 240);
}

TEST(Team, Schnellster) {
    Team t("Rot");
    EXPECT_THROW(t.schnellster(), runtime_error);
    t.aufnehmen(Laeufer("A", 60));
    t.aufnehmen(Laeufer("B", 55));
    t.aufnehmen(Laeufer("C", 55));
    const Team& ct = t;
    EXPECT_EQ(ct.schnellster().name(), "B"); // bei Gleichstand der erste
}

TEST(Team, Zugriff) {
    Team t("Gelb");
    t.aufnehmen(Laeufer("A", 60));
    t.laeufer(0).setze_zeit(58);
    const Team& ct = t;
    EXPECT_EQ(ct.laeufer(0).zeit(), 58);
    EXPECT_EQ(ct.gesamtzeit(), 58);
    EXPECT_THROW(t.laeufer(1), runtime_error);
    EXPECT_THROW(ct.laeufer(5), runtime_error);
}

TEST(Team, AufnahmeKopiert) {
    Team t("Gruen");
    Laeufer a("A", 60);
    t.aufnehmen(a);
    a.setze_zeit(10);
    EXPECT_EQ(t.laeufer(0).zeit(), 60);
}
