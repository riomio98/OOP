#include "Ringpuffer.h"
#include "alltest.h"

#include <stdexcept>

// Zusatz/Transfer zu Aufgabe 4: erst ins Projekt nehmen, wenn Teil b) dran ist

TEST_F(AllTest, Neuester) {
    Ringpuffer r(2);
    try {
        int x = r.neuester();
        (void)x;
        SuspendMemCheck smc;
        FAIL() << "neuester bei leerem Puffer muss werfen";
    } catch (std::runtime_error& e) {
        SuspendMemCheck smc;
        EXPECT_STREQ(e.what(), "empty");
    }
    r.add(1).add(2).add(3);
    const Ringpuffer& cr = r;
    SuspendMemCheck smc;
    EXPECT_EQ(cr.neuester(), 3);
}

TEST_F(AllTest, Verkleinern) {
    Ringpuffer r(5);
    for (int i = 1; i <= 7; ++i) {
        r.add(i); // enthaelt 3 4 5 6 7, Start liegt mitten im Feld
    }
    r.resize(2);
    {
        SuspendMemCheck smc;
        EXPECT_EQ(r.capacity(), 2u);
        ASSERT_EQ(r.size(), 2u);
        EXPECT_EQ(r.at(0), 6);
        EXPECT_EQ(r.at(1), 7);
    }
    r.add(8);
    SuspendMemCheck smc;
    EXPECT_EQ(r.at(0), 7);
    EXPECT_EQ(r.at(1), 8);
}

TEST_F(AllTest, Vergroessern) {
    Ringpuffer r(3);
    r.add(1).add(2).add(3).add(4); // 2 3 4
    r.resize(6);
    r.add(5).add(6).add(7);
    {
        SuspendMemCheck smc;
        EXPECT_EQ(r.capacity(), 6u);
        EXPECT_TRUE(r.full());
        EXPECT_EQ(r.at(0), 2);
        EXPECT_EQ(r.neuester(), 7);
    }
    r.add(8); // jetzt wird wieder ueberschrieben
    SuspendMemCheck smc;
    EXPECT_EQ(r.at(0), 3);
}

TEST_F(AllTest, ResizeFehler) {
    Ringpuffer r(3);
    r.add(1);
    try {
        r.resize(0);
        SuspendMemCheck smc;
        FAIL() << "resize(0) muss werfen";
    } catch (std::runtime_error& e) {
        SuspendMemCheck smc;
        EXPECT_STREQ(e.what(), "invalid capacity");
    }
    SuspendMemCheck smc;
    EXPECT_EQ(r.capacity(), 3u); // unveraendert
    EXPECT_EQ(r.at(0), 1);
}
