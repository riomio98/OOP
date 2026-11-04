#include "gtest/gtest.h"
#include "zahlen.h"

TEST(Zahlen, GgtBeispiel) {
    EXPECT_EQ(zt::ggt_rek(45, 10), 5);
    EXPECT_EQ(zt::ggt_it(45, 10), 5);
    EXPECT_EQ(zt::ggt_it(10, 45), 5);
}

TEST(Zahlen, GgtRand) {
    EXPECT_EQ(zt::ggt_it(0, 7), 7);
    EXPECT_EQ(zt::ggt_rek(7, 0), 7);
    EXPECT_EQ(zt::ggt_it(0, 0), 0);
    EXPECT_EQ(zt::ggt_rek(-8, 12), 4);
    EXPECT_EQ(zt::ggt_it(-8, -12), 4);
}

TEST(Zahlen, Kgv) {
    EXPECT_EQ(zt::kgv(4, 6), 12);
    EXPECT_EQ(zt::kgv(-4, 6), 12);
    EXPECT_EQ(zt::kgv(0, 9), 0);
    EXPECT_EQ(zt::kgv(1000000, 999999), 999999000000LL);
}

TEST(Zahlen, Teilerfremd) {
    EXPECT_TRUE(zt::teilerfremd(35, 64));
    EXPECT_FALSE(zt::teilerfremd(21, 14));
    EXPECT_FALSE(zt::teilerfremd(0, 7));
    EXPECT_TRUE(zt::teilerfremd(1, 0));
}
