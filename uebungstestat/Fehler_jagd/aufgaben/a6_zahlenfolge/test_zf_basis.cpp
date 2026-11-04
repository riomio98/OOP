#include <stdexcept>
#include <type_traits>

#include "alltest.h"
#include "Zahlenfolge.h"

using namespace std;

static_assert(!is_convertible<int, Zahlenfolge>::value,
              "Eine Zahl darf nicht unbemerkt zu einer Zahlenfolge werden");

TEST_F(AllTest, Konstruktor) {
    Zahlenfolge z;
    {
        SuspendMemCheck smc;
        EXPECT_EQ(z.size(), 0u);
        EXPECT_EQ(z.capacity(), 4u);
    }
    Zahlenfolge y(10);
    {
        SuspendMemCheck smc;
        EXPECT_EQ(y.capacity(), 10u);
        EXPECT_THROW(Zahlenfolge(0), runtime_error);
    }
}

TEST_F(AllTest, AppendOhneWachsen) {
    Zahlenfolge z(3);
    z.append(5);
    z.append(-2);
    {
        SuspendMemCheck smc;
        EXPECT_EQ(z.size(), 2u);
        EXPECT_EQ(z.at(0), 5);
        EXPECT_EQ(z.at(1), -2);
        EXPECT_EQ(z.summe(), 3);
    }
}

TEST_F(AllTest, AtSchreibenUndConst) {
    Zahlenfolge z(2);
    z.append(1);
    z.at(0) = 42;
    const Zahlenfolge& cz = z;
    {
        SuspendMemCheck smc;
        EXPECT_EQ(cz.at(0), 42);
        EXPECT_THROW(z.at(1), runtime_error);
        EXPECT_THROW(cz.at(static_cast<size_t>(-1)), runtime_error);
    }
}
