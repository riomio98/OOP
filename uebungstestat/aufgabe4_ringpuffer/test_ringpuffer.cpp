#include "Ringpuffer.h"
#include "alltest.h"

#include <stdexcept>
#include <type_traits>

// mit AllTest bei TEST_F wird Speicher ueberprueft (Lecks, double free)

void pruefe_inhalt(const Ringpuffer& r, const int* erwartet, size_t n) {
    SuspendMemCheck smc;
    ASSERT_EQ(r.size(), n);
    for (size_t i = 0; i < n; ++i) {
        EXPECT_EQ(r.at(i), erwartet[i]) << "an Index " << i;
    }
}

TEST_F(AllTest, Erzeugen) {
    Ringpuffer r(4);
    SuspendMemCheck smc;
    EXPECT_EQ(r.capacity(), 4u);
    EXPECT_EQ(r.size(), 0u);
    EXPECT_TRUE(r.empty());
    EXPECT_FALSE(r.full());
    EXPECT_FALSE((std::is_convertible<size_t, Ringpuffer>::value));
}

TEST_F(AllTest, KapazitaetNull) {
    try {
        Ringpuffer r(0);
        SuspendMemCheck smc;
        FAIL() << "Kapazitaet 0 muss werfen";
    } catch (std::runtime_error& e) {
        SuspendMemCheck smc;
        EXPECT_STREQ(e.what(), "invalid capacity");
    }
}

TEST_F(AllTest, Fuellen) {
    Ringpuffer r(3);
    r.add(10).add(20);
    int e1[]{10, 20};
    pruefe_inhalt(r, e1, 2);
    r.add(30);
    {
        SuspendMemCheck smc;
        EXPECT_TRUE(r.full());
    }
    int e2[]{10, 20, 30};
    pruefe_inhalt(r, e2, 3);
}

TEST_F(AllTest, Ueberschreiben) {
    Ringpuffer r(3);
    for (int i = 1; i <= 7; ++i) {
        r.add(i * 10);
    }
    int e[]{50, 60, 70}; // die drei neuesten, aeltester zuerst
    pruefe_inhalt(r, e, 3);
    SuspendMemCheck smc;
    EXPECT_EQ(r.capacity(), 3u);
}

TEST_F(AllTest, AtVeraendern) {
    Ringpuffer r(2);
    r.add(1).add(2).add(3); // enthaelt 2, 3
    r.at(0) = 99;
    r.at(1) += 1;
    const Ringpuffer& cr = r;
    int e[]{99, 4};
    pruefe_inhalt(cr, e, 2);
}

TEST_F(AllTest, IndexFehler) {
    Ringpuffer r(5);
    r.add(1).add(2);
    const Ringpuffer& cr = r;
    size_t falsch[]{2, 4, 5, static_cast<size_t>(-1)};
    for (size_t i : falsch) {
        try {
            r.at(i) = 0;
            SuspendMemCheck smc;
            FAIL() << "at(" << i << ") muss werfen";
        } catch (std::runtime_error& e) {
            SuspendMemCheck smc;
            EXPECT_STREQ(e.what(), "index out of range");
        }
        try {
            int x = cr.at(i);
            (void)x;
            SuspendMemCheck smc;
            FAIL() << "const at(" << i << ") muss werfen";
        } catch (std::runtime_error& e) {
            SuspendMemCheck smc;
            EXPECT_STREQ(e.what(), "index out of range");
        }
    }
}

TEST_F(AllTest, Mittel) {
    Ringpuffer r(4);
    try {
        double m = r.mittel();
        (void)m;
        SuspendMemCheck smc;
        FAIL() << "mittel bei leerem Puffer muss werfen";
    } catch (std::runtime_error& e) {
        SuspendMemCheck smc;
        EXPECT_STREQ(e.what(), "empty");
    }
    r.add(1).add(2).add(3).add(4).add(10); // enthaelt 2, 3, 4, 10
    SuspendMemCheck smc;
    EXPECT_DOUBLE_EQ(r.mittel(), 4.75);
}

TEST_F(AllTest, Clear) {
    Ringpuffer r(3);
    r.add(1).add(2).add(3).add(4);
    r.clear();
    {
        SuspendMemCheck smc;
        EXPECT_TRUE(r.empty());
        EXPECT_EQ(r.capacity(), 3u);
    }
    r.add(7);
    int e[]{7};
    pruefe_inhalt(r, e, 1);
}

TEST_F(AllTest, Kopierkonstruktor) {
    Ringpuffer a(3);
    a.add(1).add(2).add(3).add(4); // 2, 3, 4
    Ringpuffer b{a};
    Ringpuffer c = a;
    b.add(5);
    c.at(0) = -1;
    int ea[]{2, 3, 4};
    int eb[]{3, 4, 5};
    int ec[]{-1, 3, 4};
    pruefe_inhalt(a, ea, 3);
    pruefe_inhalt(b, eb, 3);
    pruefe_inhalt(c, ec, 3);
}

TEST_F(AllTest, Zuweisung) {
    Ringpuffer a(2);
    a.add(8).add(9);
    Ringpuffer b(10);
    for (int i = 0; i < 10; ++i) {
        b.add(i);
    }
    b = a;
    {
        SuspendMemCheck smc;
        EXPECT_EQ(b.capacity(), 2u);
    }
    b.add(10); // nur in b
    int ea[]{8, 9};
    int eb[]{9, 10};
    pruefe_inhalt(a, ea, 2);
    pruefe_inhalt(b, eb, 2);
}

TEST_F(AllTest, SelbstUndKettenzuweisung) {
    Ringpuffer a(3);
    a.add(1).add(2);
    Ringpuffer& ra = a;
    a = ra;
    Ringpuffer b(1);
    Ringpuffer c(7);
    c = b = a;
    a.add(3);
    int ea[]{1, 2, 3};
    int ec[]{1, 2};
    pruefe_inhalt(a, ea, 3);
    pruefe_inhalt(b, ec, 2);
    pruefe_inhalt(c, ec, 2);
}
