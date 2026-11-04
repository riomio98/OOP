#include <stdexcept>
#include <string>

#include "gtest/gtest.h"
#include "Laeufer.h"

using namespace std;

TEST(Laeufer, Erzeugen) {
    const Laeufer a("Susi");
    EXPECT_EQ(a.name(), "Susi");
    EXPECT_EQ(a.zeit(), 0);
    const Laeufer b("Rudi", 65);
    EXPECT_EQ(b.zeit(), 65);
    EXPECT_THROW(Laeufer("Bodo", -1), runtime_error);
    EXPECT_THROW(Laeufer(""), runtime_error);
}

TEST(Laeufer, ZeitSetzen) {
    Laeufer a("Susi", 50);
    EXPECT_TRUE(a.setze_zeit(71));
    EXPECT_EQ(a.zeit(), 71);
    EXPECT_FALSE(a.setze_zeit(-5));
    EXPECT_EQ(a.zeit(), 71);
}

TEST(Laeufer, Anzeige) {
    EXPECT_EQ(Laeufer("Susi", 65).anzeige(), "Susi (1:05)");
    EXPECT_EQ(Laeufer("Rudi", 9).anzeige(), "Rudi (0:09)");
    EXPECT_EQ(Laeufer("Elli", 600).anzeige(), "Elli (10:00)");
}
