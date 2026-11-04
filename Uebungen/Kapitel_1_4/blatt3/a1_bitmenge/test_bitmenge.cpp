#include <sstream>
#include <stdexcept>
#include <string>
#include <type_traits>

#include "alltest.h"
#include "Bitmenge.h"

using namespace std;

static_assert(!is_convertible<size_t, Bitmenge>::value,
              "Eine Zahl darf nicht unbemerkt zu einer Bitmenge werden");

static string text(const Bitmenge& b) {
    ostringstream os;
    b.out(os);
    return os.str();
}

TEST_F(AllTest, Erzeugen) {
    Bitmenge b(10);
    {
        SuspendMemCheck smc;
        EXPECT_EQ(b.groesse(), 10u);
        EXPECT_EQ(b.anzahl(), 0u);
        EXPECT_EQ(text(b), "0000000000");
        EXPECT_THROW(Bitmenge(0), runtime_error);
    }
}

TEST_F(AllTest, SetzenLoeschen) {
    Bitmenge b(10);
    b.setze(1);
    b.setze(8);   // liegt im zweiten Byte
    b.setze(9);
    b.setze(1);   // doppelt setzen aendert nichts
    b.loesche(9);
    const Bitmenge& cb = b;
    {
        SuspendMemCheck smc;
        EXPECT_TRUE(cb.ist_gesetzt(1));
        EXPECT_TRUE(cb.ist_gesetzt(8));
        EXPECT_FALSE(cb.ist_gesetzt(9));
        EXPECT_EQ(cb.anzahl(), 2u);
        EXPECT_EQ(text(cb), "0100000010");
    }
}

TEST_F(AllTest, Index) {
    Bitmenge b(10);
    {
        SuspendMemCheck smc;
        EXPECT_THROW(b.setze(10), runtime_error);
        EXPECT_THROW(b.loesche(static_cast<size_t>(-1)), runtime_error);
        try {
            b.ist_gesetzt(99);
            FAIL() << "keine Ausnahme";
        } catch (const runtime_error& e) {
            EXPECT_STREQ(e.what(), "index out of range");
        }
    }
}

TEST_F(AllTest, Vereinigen) {
    Bitmenge a(9), b(9), c(8);
    a.setze(0);
    b.setze(8);
    b.setze(0);
    a.vereinige(b).vereinige(b);
    {
        SuspendMemCheck smc;
        EXPECT_EQ(text(a), "100000001");
        EXPECT_EQ(text(b), "100000001");
        EXPECT_THROW(a.vereinige(c), runtime_error);
    }
}

TEST_F(AllTest, Kopie) {
    Bitmenge a(12);
    a.setze(3);
    Bitmenge b(a);
    b.setze(11);
    {
        SuspendMemCheck smc;
        EXPECT_EQ(text(a), "000100000000");
        EXPECT_EQ(text(b), "000100000001");
    }
}

TEST_F(AllTest, Zuweisung) {
    Bitmenge a(20), b(3), c(5);
    a.setze(19);
    b = a;
    a.loesche(19);
    Bitmenge& rb = b;
    b = rb;
    c = b = b;
    {
        SuspendMemCheck smc;
        EXPECT_EQ(b.groesse(), 20u);
        EXPECT_TRUE(b.ist_gesetzt(19));
        EXPECT_FALSE(a.ist_gesetzt(19));
        EXPECT_EQ(c.anzahl(), 1u);
    }
}
