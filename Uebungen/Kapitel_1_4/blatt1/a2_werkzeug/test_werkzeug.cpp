#include <stdexcept>
#include <string>

#include "gtest/gtest.h"
#include "werkzeug.h"

using namespace std;

TEST(Werkzeug, Sortiere3) {
    int a = 3, b = 1, c = 2;
    wz::sortiere3(a, b, c);
    EXPECT_EQ(a, 1);
    EXPECT_EQ(b, 2);
    EXPECT_EQ(c, 3);
    int x = 5, y = 5, z = -1;
    wz::sortiere3(x, y, z);
    EXPECT_EQ(x, -1);
    EXPECT_EQ(z, 5);
}

TEST(Werkzeug, ElementVorneHinten) {
    int f[5] = {10, 20, 30, 40, 50};
    EXPECT_EQ(wz::element(f, 5, 0), 10);
    EXPECT_EQ(wz::element(f, 5, 4), 50);
    EXPECT_EQ(wz::element(f, 5, -1), 50);
    EXPECT_EQ(wz::element(f, 5, -5), 10);
    wz::element(f, 5, -2) = 99;
    EXPECT_EQ(f[3], 99);
}

TEST(Werkzeug, ElementFehler) {
    int f[3] = {1, 2, 3};
    EXPECT_THROW(wz::element(f, 3, 3), runtime_error);
    EXPECT_THROW(wz::element(f, 3, -4), runtime_error);
    try {
        wz::element(f, 3, 1234567);
        FAIL() << "keine Ausnahme";
    } catch (const runtime_error& e) {
        EXPECT_STREQ(e.what(), "index out of range");
    }
}

TEST(Werkzeug, Teile) {
    int q = -1, r = -1;
    EXPECT_TRUE(wz::teile(17, 5, q, r));
    EXPECT_EQ(q, 3);
    EXPECT_EQ(r, 2);
    EXPECT_FALSE(wz::teile(17, 0, q, r));
    EXPECT_EQ(q, 3);
    EXPECT_EQ(r, 2);
}

TEST(Werkzeug, Zaehle) {
    EXPECT_EQ(wz::zaehle("Ene Mene Muh"), 2u);
    EXPECT_EQ(wz::zaehle("Ene Mene Muh", 'e'), 3u);
    EXPECT_EQ(wz::zaehle(""), 0u);
    const string s = "a,b,,c";
    EXPECT_EQ(wz::zaehle(s, ','), 3u);
}

TEST(Werkzeug, Wiederhole) {
    EXPECT_EQ(wz::wiederhole("ab"), "abab");
    EXPECT_EQ(wz::wiederhole("ab", 3), "ababab");
    EXPECT_EQ(wz::wiederhole("ab", 3, "-"), "ab-ab-ab");
    EXPECT_EQ(wz::wiederhole("x", 0, "-"), "");
    EXPECT_THROW(wz::wiederhole("x", -1), runtime_error);
}
