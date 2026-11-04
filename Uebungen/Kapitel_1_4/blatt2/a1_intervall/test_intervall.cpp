#include <sstream>
#include <stdexcept>
#include <string>

#include "gtest/gtest.h"
#include "Intervall.h"

using namespace std;

static string text(const Intervall& i) {
    ostringstream os;
    i.out(os);
    return os.str();
}

TEST(Intervall, Erzeugen) {
    const Intervall a;
    const Intervall b(5);
    const Intervall c(3, 7);
    const Intervall d(7, 3);
    EXPECT_EQ(text(a), "[0, 0]");
    EXPECT_EQ(text(b), "[5, 5]");
    EXPECT_EQ(text(c), "[3, 7]");
    EXPECT_EQ(text(d), "[3, 7]");
    EXPECT_EQ(c.von(), 3);
    EXPECT_EQ(c.bis(), 7);
}

TEST(Intervall, Laenge) {
    EXPECT_EQ(Intervall(3, 7).laenge(), 5);
    EXPECT_EQ(Intervall(-2).laenge(), 1);
    EXPECT_EQ(Intervall(-3, 3).laenge(), 7);
}

TEST(Intervall, EnthaeltZahl) {
    const Intervall c(3, 7);
    EXPECT_TRUE(c.enthaelt(3));
    EXPECT_TRUE(c.enthaelt(7));
    EXPECT_FALSE(c.enthaelt(8));
    EXPECT_FALSE(c.enthaelt(2));
}

TEST(Intervall, EnthaeltIntervall) {
    const Intervall c(3, 7);
    EXPECT_TRUE(c.enthaelt(Intervall(4, 6)));
    EXPECT_TRUE(c.enthaelt(c));
    EXPECT_FALSE(c.enthaelt(Intervall(6, 8)));
}

TEST(Intervall, Ueberlappt) {
    const Intervall c(3, 7);
    EXPECT_TRUE(c.ueberlappt(Intervall(7, 9)));
    EXPECT_TRUE(c.ueberlappt(Intervall(0, 3)));
    EXPECT_FALSE(c.ueberlappt(Intervall(8, 9)));
    EXPECT_TRUE(c.ueberlappt(5));   // Zahl wird zum Einpunktintervall
    EXPECT_FALSE(c.ueberlappt(10));
}

TEST(Intervall, Verschieben) {
    Intervall c(3, 7);
    c.verschiebe(2).verschiebe(-10);
    EXPECT_EQ(text(c), "[-5, -1]");
}

TEST(Intervall, Vereinigung) {
    const Intervall c(3, 7);
    EXPECT_EQ(text(c.vereinigung(Intervall(6, 10))), "[3, 10]");
    EXPECT_EQ(text(c.vereinigung(Intervall(8, 9))), "[3, 9]");   // angrenzend
    EXPECT_EQ(text(c.vereinigung(Intervall(4, 5))), "[3, 7]");
    EXPECT_EQ(text(c.vereinigung(2)), "[2, 7]");
    EXPECT_THROW(c.vereinigung(Intervall(9, 12)), runtime_error);
    EXPECT_EQ(text(c), "[3, 7]");
}
