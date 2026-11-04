#include <sstream>
#include <stdexcept>

#include "gtest/gtest.h"
#include "Datum.h"

using namespace std;

static string text(const Datum& d) {
    ostringstream os;
    d.out(os);
    return os.str();
}

TEST(Datum, Vorgabe) {
    const Datum d;
    EXPECT_EQ(d.tag(), 1);
    EXPECT_EQ(d.monat(), 1);
    EXPECT_EQ(d.jahr(), 1970);
    EXPECT_EQ(text(d), "01.01.1970");
}

TEST(Datum, TeilweiseVorgabe) {
    const Datum d(17, 3);
    EXPECT_EQ(text(d), "17.03.1970");
}

TEST(Datum, Ungueltig) {
    EXPECT_THROW(Datum(0, 1, 2026), runtime_error);
    EXPECT_THROW(Datum(31, 4, 2026), runtime_error);
    EXPECT_THROW(Datum(1, 13, 2026), runtime_error);
    EXPECT_THROW(Datum(29, 2, 2026), runtime_error);
    EXPECT_NO_THROW(Datum(29, 2, 2024));
}

TEST(Datum, Schaltjahr) {
    EXPECT_TRUE(Datum::schaltjahr(2024));
    EXPECT_FALSE(Datum::schaltjahr(2026));
    EXPECT_FALSE(Datum::schaltjahr(1900));
    EXPECT_TRUE(Datum::schaltjahr(2000));
    EXPECT_NO_THROW(Datum(29, 2, 2000));
}

TEST(Datum, NaechsterTag) {
    Datum d(28, 2, 2026);
    d.naechster_tag();
    EXPECT_EQ(text(d), "01.03.2026");
    Datum e(30, 4, 2026);
    e.naechster_tag();
    EXPECT_EQ(text(e), "01.05.2026");
}

TEST(Datum, Jahreswechsel) {
    Datum d(31, 12, 2026);
    d.naechster_tag();
    EXPECT_EQ(text(d), "01.01.2027");
}

TEST(Datum, AddiereTage) {
    Datum d(20, 12, 2026);
    d.addiere_tage(45);
    EXPECT_EQ(text(d), "03.02.2027");
    EXPECT_THROW(d.addiere_tage(-1), runtime_error);
    EXPECT_EQ(text(d), "03.02.2027");
}

TEST(Datum, Vor) {
    const Datum a(15, 6, 2026);
    EXPECT_TRUE(a.vor(Datum(16, 6, 2026)));
    EXPECT_TRUE(a.vor(Datum(1, 7, 2026)));
    EXPECT_TRUE(a.vor(Datum(1, 1, 2027)));
    EXPECT_FALSE(a.vor(a));
    EXPECT_FALSE(a.vor(Datum(14, 6, 2026)));
    EXPECT_FALSE(a.vor(Datum(20, 5, 2026)));
    EXPECT_FALSE(a.vor(Datum(30, 12, 2025)));
}
