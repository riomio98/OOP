#include "alltest.h"
#include "simplemath.h"

// Aufgabe 1: Tests 1 bis 3

TEST_F(AllTest, quadrat) {
    SuspendMemCheck smc;
    EXPECT_EQ(25, quadrat(5));
    EXPECT_EQ(9, quadrat(-3));
    EXPECT_EQ(0, quadrat(0));
}

TEST_F(AllTest, kubik) {
    SuspendMemCheck smc;
    EXPECT_EQ(27, kubik(3));
    EXPECT_EQ(-8, kubik(-2));
    EXPECT_EQ(1, kubik(1));
}

TEST_F(AllTest, hoch4) {
    SuspendMemCheck smc;
    EXPECT_EQ(81, hoch4(3));
    EXPECT_EQ(16, hoch4(-2));
    EXPECT_EQ(100000000L, hoch4(100));
}
