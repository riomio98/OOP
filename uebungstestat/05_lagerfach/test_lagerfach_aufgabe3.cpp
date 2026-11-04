// Google-Tests zu Probetestat 3, Aufgabe 3: Lagerfachverwaltung
// In dasselbe Eclipse-Projekt wie Lagerfach.h und Lagerfach.cpp kopieren.
// Erwartete frei stehende Funktion: umlagern(Lagerfach&, Lagerfach&, size_t)
// Der Test verlangt KEINEN Rueckgabetyp fuer umlagern (void oder bool moeglich).

#include <gtest/gtest.h>
#include "lagerfach.h"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include <type_traits>

static_assert(!std::is_convertible<std::size_t, Lagerfach>::value,
              "Der Kapazitaets-Konstruktor muss explicit sein.");
static_assert(!std::is_copy_constructible<Lagerfach>::value,
              "Ein Lagerfach darf nicht kopiert werden.");
static_assert(!std::is_copy_assignable<Lagerfach>::value,
              "Ein Lagerfach darf nicht zugewiesen werden.");

TEST(LagerfachTest, NeuesFachIstLeerUndConstAbfragbar)
{
    const auto basis = Lagerfach::gesamtbestand();
    {
        const Lagerfach fach{5};
        EXPECT_EQ(fach.capacity(), 5u);
        EXPECT_EQ(fach.bestand(), 0u);
        EXPECT_EQ(Lagerfach::gesamtbestand(), basis);
    }
    EXPECT_EQ(Lagerfach::gesamtbestand(), basis);
}

TEST(LagerfachTest, KapazitaetNullWirftPassendenFehler)
{
    const auto basis = Lagerfach::gesamtbestand();
    try {
        Lagerfach fach{0};
        FAIL() << "Kapazitaet 0 muss eine runtime_error ausloesen.";
    } catch (const std::runtime_error& e) {
        EXPECT_EQ(std::string(e.what()), "invalid capacity");
    }
    EXPECT_EQ(Lagerfach::gesamtbestand(), basis);
}

TEST(LagerfachTest, EinlagernBisZurKapazitaet)
{
    const auto basis = Lagerfach::gesamtbestand();
    {
        Lagerfach fach{3};
        EXPECT_TRUE(fach.einlagern(2));
        EXPECT_EQ(fach.bestand(), 2u);
        EXPECT_EQ(Lagerfach::gesamtbestand(), basis + 2);

        EXPECT_TRUE(fach.einlagern(1));
        EXPECT_EQ(fach.bestand(), 3u);
        EXPECT_EQ(Lagerfach::gesamtbestand(), basis + 3);

        EXPECT_FALSE(fach.einlagern(1));
        EXPECT_EQ(fach.bestand(), 3u);
        EXPECT_EQ(Lagerfach::gesamtbestand(), basis + 3);
    }
    EXPECT_EQ(Lagerfach::gesamtbestand(), basis);
}

TEST(LagerfachTest, EntnehmenUndNullmenge)
{
    const auto basis = Lagerfach::gesamtbestand();
    {
        Lagerfach fach{4};
        EXPECT_TRUE(fach.einlagern(0));
        EXPECT_TRUE(fach.entnehmen(0));
        EXPECT_FALSE(fach.entnehmen(1));
        EXPECT_EQ(fach.bestand(), 0u);

        ASSERT_TRUE(fach.einlagern(3));
        EXPECT_FALSE(fach.entnehmen(4));
        EXPECT_EQ(fach.bestand(), 3u);
        EXPECT_EQ(Lagerfach::gesamtbestand(), basis + 3);

        EXPECT_TRUE(fach.entnehmen(2));
        EXPECT_EQ(fach.bestand(), 1u);
        EXPECT_TRUE(fach.entnehmen(1));
        EXPECT_EQ(fach.bestand(), 0u);
        EXPECT_EQ(Lagerfach::gesamtbestand(), basis);
    }
    EXPECT_EQ(Lagerfach::gesamtbestand(), basis);
}

TEST(LagerfachTest, GesamtbestandMehrererFaecherUndDestruktor)
{
    const auto basis = Lagerfach::gesamtbestand();
    {
        Lagerfach a{5};
        ASSERT_TRUE(a.einlagern(4));
        EXPECT_EQ(Lagerfach::gesamtbestand(), basis + 4);

        {
            Lagerfach b{3};
            ASSERT_TRUE(b.einlagern(2));
            EXPECT_EQ(Lagerfach::gesamtbestand(), basis + 6);
        } // b wird zerstoert: 2 verschwinden aus gesamtbestand()

        EXPECT_EQ(Lagerfach::gesamtbestand(), basis + 4);
    } // a wird zerstoert
    EXPECT_EQ(Lagerfach::gesamtbestand(), basis);
}

TEST(LagerfachTest, UmlagernErfolgreichUndGesamtbestandUnveraendert)
{
    const auto basis = Lagerfach::gesamtbestand();
    {
        Lagerfach a{5};
        Lagerfach b{3};
        ASSERT_TRUE(a.einlagern(4));

        umlagern(a, b, 2); // Rueckgabewert absichtlich nicht geprueft

        EXPECT_EQ(a.bestand(), 2u);
        EXPECT_EQ(b.bestand(), 2u);
        EXPECT_EQ(Lagerfach::gesamtbestand(), basis + 4);
    }
    EXPECT_EQ(Lagerfach::gesamtbestand(), basis);
}

TEST(LagerfachTest, UmlagernOhnePlatzOderBestandAendertNichts)
{
    const auto basis = Lagerfach::gesamtbestand();
    {
        Lagerfach a{5};
        Lagerfach b{3};
        ASSERT_TRUE(a.einlagern(2));
        ASSERT_TRUE(b.einlagern(2));

        // Quelle hat zu wenig Bestand
        umlagern(a, b, 3);
        EXPECT_EQ(a.bestand(), 2u);
        EXPECT_EQ(b.bestand(), 2u);
        EXPECT_EQ(Lagerfach::gesamtbestand(), basis + 4);

        // Ziel hat zu wenig Platz
        umlagern(a, b, 2);
        EXPECT_EQ(a.bestand(), 2u);
        EXPECT_EQ(b.bestand(), 2u);
        EXPECT_EQ(Lagerfach::gesamtbestand(), basis + 4);
    }
    EXPECT_EQ(Lagerfach::gesamtbestand(), basis);
}

TEST(LagerfachTest, UmlagernMitSichSelbstAendertNichts)
{
    const auto basis = Lagerfach::gesamtbestand();
    {
        Lagerfach a{5};
        ASSERT_TRUE(a.einlagern(4));

        umlagern(a, a, 2);
        EXPECT_EQ(a.bestand(), 4u);
        EXPECT_EQ(Lagerfach::gesamtbestand(), basis + 4);
    }
    EXPECT_EQ(Lagerfach::gesamtbestand(), basis);
}

TEST(LagerfachTest, GrenzfallSehrGrosseEinlagerungsmenge)
{
    const auto basis = Lagerfach::gesamtbestand();
    {
        Lagerfach a{3};
        ASSERT_TRUE(a.einlagern(1));
        EXPECT_FALSE(a.einlagern(std::numeric_limits<std::size_t>::max()));
        EXPECT_EQ(a.bestand(), 1u);
        EXPECT_EQ(Lagerfach::gesamtbestand(), basis + 1);
    }
    EXPECT_EQ(Lagerfach::gesamtbestand(), basis);
}
