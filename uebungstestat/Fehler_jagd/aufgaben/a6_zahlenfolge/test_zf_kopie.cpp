#include "alltest.h"
#include "Zahlenfolge.h"

using namespace std;

static Zahlenfolge folge(int von, int bis) {
    Zahlenfolge z(8); // gross genug, kein Wachsen noetig
    for (int i = von; i <= bis; ++i) {
        z.append(i);
    }
    return z;
}

TEST_F(AllTest, Kopierkonstruktor) {
    Zahlenfolge a = folge(1, 3);
    Zahlenfolge b(a);
    b.at(0) = 99;
    {
        SuspendMemCheck smc;
        EXPECT_EQ(a.at(0), 1);
        EXPECT_EQ(b.at(0), 99);
        EXPECT_EQ(b.size(), 3u);
    }
}

TEST_F(AllTest, ZuweisungVerschiedeneGroessen) {
    Zahlenfolge a = folge(1, 5);
    Zahlenfolge b(1);
    b = a;
    {
        SuspendMemCheck smc;
        EXPECT_EQ(b.size(), 5u);
        EXPECT_EQ(b.summe(), 15);
    }
    a.at(4) = 0;
    {
        SuspendMemCheck smc;
        EXPECT_EQ(b.at(4), 5);
    }
}

TEST_F(AllTest, Selbstzuweisung) {
    Zahlenfolge a = folge(7, 9);
    Zahlenfolge& r = a;
    a = r;
    {
        SuspendMemCheck smc;
        EXPECT_EQ(a.size(), 3u);
        EXPECT_EQ(a.at(0), 7);
        EXPECT_EQ(a.at(1), 8);
        EXPECT_EQ(a.at(2), 9);
    }
}

TEST_F(AllTest, Kettenzuweisung) {
    Zahlenfolge a(1), b(1);
    Zahlenfolge c = folge(4, 6);
    a = b = c;
    {
        SuspendMemCheck smc;
        EXPECT_EQ(a.summe(), 15);
        EXPECT_EQ(b.summe(), 15);
    }
}
