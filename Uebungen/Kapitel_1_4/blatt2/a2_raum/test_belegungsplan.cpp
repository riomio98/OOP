#include <stdexcept>

#include "gtest/gtest.h"
#include "Belegungsplan.h"
#include "Intervall.h"

using namespace std;

TEST(Belegungsplan, Leer) {
    const Belegungsplan p("A101");
    EXPECT_EQ(p.raum(), "A101");
    EXPECT_EQ(p.oeffnung().von(), 480);
    EXPECT_EQ(p.oeffnung().bis(), 1199);
    EXPECT_EQ(p.anzahl(), 0u);
    EXPECT_EQ(p.freie_minuten(), 720);
    EXPECT_THROW(p.reservierung(0), runtime_error);
}

TEST(Belegungsplan, Reservieren) {
    Belegungsplan p("B2", Intervall(0, 99));
    EXPECT_TRUE(p.reservieren(Intervall(10, 19)));
    EXPECT_TRUE(p.reservieren(Intervall(20, 29)));   // direkt danach ist frei
    EXPECT_FALSE(p.reservieren(Intervall(15, 25)));  // Ueberschneidung
    EXPECT_FALSE(p.reservieren(Intervall(90, 100))); // ausserhalb der Oeffnung
    EXPECT_TRUE(p.reservieren(50));                  // eine einzelne Minute
    EXPECT_EQ(p.anzahl(), 3u);
    EXPECT_EQ(p.belegte_minuten(), 21);
    EXPECT_EQ(p.freie_minuten(), 79);
    EXPECT_EQ(p.reservierung(1).von(), 20);
}

TEST(Belegungsplan, Stornieren) {
    Belegungsplan p("C3", Intervall(0, 99));
    p.reservieren(Intervall(10, 19));
    p.reservieren(Intervall(30, 39));
    EXPECT_FALSE(p.stornieren(25));
    EXPECT_TRUE(p.stornieren(12));
    EXPECT_EQ(p.anzahl(), 1u);
    EXPECT_EQ(p.reservierung(0).von(), 30);
    EXPECT_TRUE(p.reservieren(Intervall(15, 25)));
}
