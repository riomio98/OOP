// Nur dieser Test ist gegeben. Leiten Sie Thermostat.h und Thermostat.cpp ab.
#include <stdexcept>
#include <string>
#include <type_traits>

#include "gtest/gtest.h"
#include "Thermostat.h"

using namespace std;

static_assert(!is_convertible<double, Thermostat>::value,
              "Eine Zahl darf nicht unbemerkt zu einem Thermostat werden");
static_assert(!is_copy_constructible<Thermostat>::value, "nicht kopierbar");
static_assert(!is_copy_assignable<Thermostat>::value, "nicht zuweisbar");

TEST(Thermostat, Vorgaben) {
    const Thermostat t;
    EXPECT_DOUBLE_EQ(t.soll(), 20.0);
    EXPECT_EQ(t.raum(), "Flur");
    const Thermostat k(18.5);
    EXPECT_DOUBLE_EQ(k.soll(), 18.5);
    const Thermostat b(22.0, "Bad");
    EXPECT_EQ(b.raum(), "Bad");
}

TEST(Thermostat, RaumOhneKopie) {
    const Thermostat t(21.0, "Kueche");
    const string& r1 = t.raum();
    const string& r2 = t.raum();
    EXPECT_EQ(&r1, &r2);
}

TEST(Thermostat, StelleWirdBegrenzt) {
    Thermostat t;
    EXPECT_TRUE(t.stelle(23.5));
    EXPECT_DOUBLE_EQ(t.soll(), 23.5);
    EXPECT_FALSE(t.stelle(40.0));
    EXPECT_DOUBLE_EQ(t.soll(), 30.0);
    EXPECT_FALSE(t.stelle(-3.0));
    EXPECT_DOUBLE_EQ(t.soll(), 5.0);
}

TEST(Thermostat, UngueltigerStartwert) {
    EXPECT_THROW(Thermostat(35.0), runtime_error);
    EXPECT_THROW(Thermostat(20.0, ""), runtime_error);
}

TEST(Thermostat, Heizen) {
    Thermostat t(20.0);
    EXPECT_TRUE(t.heizen(19.0));
    EXPECT_FALSE(t.heizen(20.0));
    t.korrektur() = 1.5; // Fuehler misst 1.5 Grad zu wenig
    EXPECT_FALSE(t.heizen(19.0));
    const Thermostat& ct = t;
    EXPECT_DOUBLE_EQ(ct.korrektur(), 1.5);
    EXPECT_TRUE(ct.heizen(18.0));
}

TEST(Thermostat, Anzahl) {
    int vorher = Thermostat::anzahl();
    {
        Thermostat a, b(19.0);
        EXPECT_EQ(Thermostat::anzahl(), vorher + 2);
    }
    EXPECT_EQ(Thermostat::anzahl(), vorher);
    EXPECT_THROW(Thermostat(99.0), runtime_error);
    EXPECT_EQ(Thermostat::anzahl(), vorher);
}

TEST(Thermostat, Synchronisieren) {
    Thermostat ziel(18.0, "Bad");
    const Thermostat quelle(22.5, "Flur");
    synchronisiere(ziel, quelle);
    EXPECT_DOUBLE_EQ(ziel.soll(), 22.5);
    EXPECT_EQ(ziel.raum(), "Bad");
}
