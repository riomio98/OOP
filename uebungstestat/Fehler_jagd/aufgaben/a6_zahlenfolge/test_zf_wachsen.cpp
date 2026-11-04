#include "alltest.h"
#include "Zahlenfolge.h"

using namespace std;

TEST_F(AllTest, WachsenEinmal) {
    Zahlenfolge z(2);
    z.append(10);
    z.append(20);
    z.append(30);
    {
        SuspendMemCheck smc;
        EXPECT_EQ(z.capacity(), 4u);
        EXPECT_EQ(z.size(), 3u);
        EXPECT_EQ(z.at(0), 10);
        EXPECT_EQ(z.at(1), 20);
        EXPECT_EQ(z.at(2), 30);
    }
}

TEST_F(AllTest, WachsenMehrfach) {
    Zahlenfolge z(1);
    for (int i = 1; i <= 9; ++i) {
        z.append(i);
    }
    {
        SuspendMemCheck smc;
        EXPECT_EQ(z.capacity(), 16u);
        EXPECT_EQ(z.summe(), 45);
    }
    for (size_t i = 0; i < z.size(); ++i) {
        {
            SuspendMemCheck smc;
            EXPECT_EQ(z.at(i), static_cast<int>(i) + 1);
        }
    }
}
