#include <stdexcept>
#include <vector>

#include "gtest/gtest.h"
#include "feld.h"

using namespace std;

TEST(Grenzen, Gemischt) {
    const vector<int> v{-3, 5, 2};
    int mn = 99, mx = 99;
    grenzen(v, mn, mx);
    EXPECT_EQ(mn, -3);
    EXPECT_EQ(mx, 5);
}

TEST(Grenzen, NurPositiv) {
    const vector<int> v{4, 7, 5};
    int mn = 0, mx = 0;
    grenzen(v, mn, mx);
    EXPECT_EQ(mn, 4);
    EXPECT_EQ(mx, 7);
}

TEST(Grenzen, NurNegativ) {
    const vector<int> v{-8, -2, -5};
    int mn = 0, mx = 0;
    grenzen(v, mn, mx);
    EXPECT_EQ(mn, -8);
    EXPECT_EQ(mx, -2);
}

TEST(Grenzen, Leer) {
    const vector<int> v;
    int mn = 11, mx = 22;
    EXPECT_THROW(grenzen(v, mn, mx), runtime_error);
    EXPECT_EQ(mn, 11);
    EXPECT_EQ(mx, 22);
}

TEST(Entferne, Einzeln) {
    vector<int> v{1, 2, 3};
    EXPECT_EQ(entferne(v, 2), 1u);
    EXPECT_EQ(v, (vector<int>{1, 3}));
}

TEST(Entferne, NichtVorhanden) {
    vector<int> v{1, 2, 3};
    EXPECT_EQ(entferne(v, 7), 0u);
    EXPECT_EQ(v.size(), 3u);
}

TEST(Entferne, Nachbarn) {
    vector<int> v{2, 2, 1, 2, 2};
    EXPECT_EQ(entferne(v, 2), 4u);
    EXPECT_EQ(v, (vector<int>{1}));
}

TEST(Tausche, Zeiger) {
    int x = 1, y = 2;
    int* px = &x;
    int* py = &y;
    tausche(px, py);
    EXPECT_EQ(px, &y);
    EXPECT_EQ(py, &x);
    EXPECT_EQ(x, 1);
}

TEST(Groesstes, Lesen) {
    vector<int> v{3, 9, 9, 1};
    EXPECT_EQ(groesstes(v), 9);
    EXPECT_THROW(
        {
            vector<int> leer;
            groesstes(leer);
        },
        runtime_error);
}

TEST(Groesstes, Veraendern) {
    vector<int> v{3, 9, 9, 1};
    groesstes(v) = 0;
    EXPECT_EQ(v, (vector<int>{3, 0, 9, 1}));
}
