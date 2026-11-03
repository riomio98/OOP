#include "Fahrrad.h"
#include "Station.h"
#include "alltest.h"

#include <stdexcept>

// Zusatz/Transfer zu Aufgabe 3: erst ins Projekt nehmen, wenn Teil b) dran ist
// mit AllTest bei TEST_F wird Speicher ueberprueft (Lecks, double free)

TEST_F(AllTest, StationErzeugen) {
    Station s{"Hauptbahnhof", 3};
    {
        SuspendMemCheck smc;
        EXPECT_EQ(s.name(), "Hauptbahnhof");
        EXPECT_EQ(s.plaetze(), 3u);
        EXPECT_EQ(s.belegt(), 0u);
        EXPECT_EQ(s.frei(), 3u);
    }
    try {
        Station kaputt{"X", 0};
        SuspendMemCheck smc;
        FAIL() << "0 Plaetze muss werfen";
    } catch (std::runtime_error& e) {
        SuspendMemCheck smc;
        EXPECT_STREQ(e.what(), "invalid size");
    }
}

TEST_F(AllTest, EinstellenEntnehmen) {
    Fahrrad a{"A"};
    Fahrrad b{"B"};
    Fahrrad c{"C"};
    Fahrrad d{"D"};
    Station s{"Uni", 3};
    bool r1 = s.einstellen(a);
    bool r2 = s.einstellen(a); // schon da
    d.ausleihen();
    bool r3 = s.einstellen(d); // ist unterwegs
    bool r4 = s.einstellen(b);
    bool r5 = s.einstellen(c);
    d.zurueckgeben(0);
    bool r6 = s.einstellen(d); // voll
    {
        SuspendMemCheck smc;
        EXPECT_TRUE(r1);
        EXPECT_FALSE(r2);
        EXPECT_FALSE(r3);
        EXPECT_TRUE(r4);
        EXPECT_TRUE(r5);
        EXPECT_FALSE(r6);
        EXPECT_EQ(s.frei(), 0u);
    }
    Fahrrad* weg = s.entnehmen(b.nummer());
    Fahrrad* nix = s.entnehmen(b.nummer());
    bool r7 = s.einstellen(d); // jetzt frei
    SuspendMemCheck smc;
    EXPECT_EQ(weg, &b);
    EXPECT_EQ(nix, nullptr);
    EXPECT_TRUE(r7);
    EXPECT_EQ(s.belegt(), 3u);
}

TEST_F(AllTest, FindeUndWartung) {
    Fahrrad a{"A"};
    Fahrrad b{"B"};
    a.ausleihen();
    a.zurueckgeben(600);
    Station s{"Park", 4};
    s.einstellen(a);
    s.einstellen(b);
    s.finde(b.nummer())->ausleihen(); // ueber die Station veraendern
    const Station& cs = s;
    SuspendMemCheck smc;
    EXPECT_TRUE(b.ausgeliehen());
    EXPECT_EQ(cs.finde(a.nummer()), &a);
    EXPECT_EQ(cs.finde(99999), nullptr);
    EXPECT_EQ(cs.wartungsbedarf(), 1);
    EXPECT_EQ(cs.wartungsbedarf(700), 0);
    b.zurueckgeben(0);
}

TEST_F(AllTest, StationKopie) {
    Fahrrad a{"A"};
    Fahrrad b{"B"};
    Station s{"Nord", 2};
    s.einstellen(a);
    Station t{s}; // eigene Platzbelegung, dieselben Fahrraeder
    t.einstellen(b);
    s.entnehmen(a.nummer());
    SuspendMemCheck smc;
    EXPECT_EQ(s.belegt(), 0u);
    EXPECT_EQ(t.belegt(), 2u);
    EXPECT_EQ(t.finde(a.nummer()), &a);
}

TEST_F(AllTest, StationZuweisung) {
    Fahrrad a{"A"};
    Station s{"Nord", 1};
    Station t{"Sued", 5};
    s.einstellen(a);
    t = s;
    Station& rt = t;
    t = rt;
    Station u{"West", 2};
    u = t = s;
    s.entnehmen(a.nummer());
    SuspendMemCheck smc;
    EXPECT_EQ(t.name(), "Nord");
    EXPECT_EQ(t.plaetze(), 1u);
    EXPECT_EQ(t.belegt(), 1u);
    EXPECT_EQ(u.finde(a.nummer()), &a);
    EXPECT_EQ(s.belegt(), 0u);
}
