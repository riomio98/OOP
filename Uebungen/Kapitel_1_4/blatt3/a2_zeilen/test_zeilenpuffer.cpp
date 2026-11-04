#include <stdexcept>
#include <string>

#include "alltest.h"
#include "Zeilenpuffer.h"

using namespace std;

static void fuelle(Zeilenpuffer& p, int n) {
    for (int i = 0; i < n; ++i) {
        p.anhaengen("Zeile " + to_string(i) + " mit genug Text gegen kurze Strings");
    }
}

TEST_F(AllTest, Erzeugen) {
    Zeilenpuffer p;
    {
        SuspendMemCheck smc;
        EXPECT_EQ(p.size(), 0u);
        EXPECT_EQ(p.kapazitaet(), 2u);
        EXPECT_THROW(Zeilenpuffer(0), runtime_error);
    }
}

TEST_F(AllTest, AnhaengenUndWachsen) {
    Zeilenpuffer p(1);
    fuelle(p, 5);
    {
        SuspendMemCheck smc;
        EXPECT_EQ(p.size(), 5u);
        EXPECT_EQ(p.kapazitaet(), 8u);
        EXPECT_EQ(p.zeile(0).substr(0, 7), "Zeile 0");
        EXPECT_EQ(p.zeile(4).substr(0, 7), "Zeile 4");
    }
}

TEST_F(AllTest, ZugriffConst) {
    Zeilenpuffer p;
    p.anhaengen("a");
    p.zeile(0) += "b";
    const Zeilenpuffer& cp = p;
    {
        SuspendMemCheck smc;
        EXPECT_EQ(cp.zeile(0), "ab");
        EXPECT_THROW(cp.zeile(1), runtime_error);
        EXPECT_THROW(p.zeile(static_cast<size_t>(-1)), runtime_error);
    }
}

TEST_F(AllTest, Entferne) {
    Zeilenpuffer p;
    p.anhaengen("eins");
    p.anhaengen("zwei");
    p.anhaengen("drei");
    p.entferne(0);
    {
        SuspendMemCheck smc;
        EXPECT_EQ(p.size(), 2u);
        EXPECT_EQ(p.zeile(0), "zwei");
        EXPECT_EQ(p.zeile(1), "drei");
        EXPECT_THROW(p.entferne(2), runtime_error);
    }
}

TEST_F(AllTest, Finde) {
    Zeilenpuffer p;
    p.anhaengen("Ene Mene");
    p.anhaengen("Muh");
    p.anhaengen("und raus bist Mene");
    const Zeilenpuffer& cp = p;
    {
        SuspendMemCheck smc;
        EXPECT_EQ(cp.finde("Mene"), 0u);
        EXPECT_EQ(cp.finde("Mene", 1), 2u);
        EXPECT_EQ(cp.finde("Du"), cp.size());
    }
}

TEST_F(AllTest, Kopie) {
    Zeilenpuffer a;
    fuelle(a, 3);
    Zeilenpuffer b(a);
    b.zeile(0) = "geaendert";
    {
        SuspendMemCheck smc;
        EXPECT_EQ(b.size(), 3u);
        EXPECT_EQ(a.zeile(0).substr(0, 7), "Zeile 0");
    }
}

TEST_F(AllTest, Zuweisung) {
    Zeilenpuffer a, b(1), c(7);
    fuelle(a, 5);
    b = a;
    Zeilenpuffer& rb = b;
    b = rb;
    c = b = a;
    a.zeile(4) = "x";
    {
        SuspendMemCheck smc;
        EXPECT_EQ(b.size(), 5u);
        EXPECT_EQ(c.size(), 5u);
        EXPECT_EQ(c.zeile(4).substr(0, 7), "Zeile 4");
    }
}
