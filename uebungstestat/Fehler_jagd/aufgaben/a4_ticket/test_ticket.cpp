#include <stdexcept>
#include <type_traits>

#include "gtest/gtest.h"
#include "Ticket.h"

using namespace std;

static_assert(!is_convertible<string, Ticket>::value,
              "Ein string darf nicht unbemerkt zu einem Ticket werden");

TEST(Ticket, Nummern) {
    const Ticket a("Susi");
    const Ticket b("Rudi");
    EXPECT_EQ(b.nr(), a.nr() + 1);
    EXPECT_EQ(a.kunde(), "Susi");
}

TEST(Ticket, AktiveImBlock) {
    int vorher = Ticket::aktive();
    {
        Ticket a("Susi");
        Ticket b("Rudi");
        EXPECT_EQ(Ticket::aktive(), vorher + 2);
    }
    EXPECT_EQ(Ticket::aktive(), vorher);
}

TEST(Ticket, Fehlschlag) {
    int vorher = Ticket::aktive();
    Ticket a("Susi");
    EXPECT_THROW(Ticket(""), runtime_error);
    EXPECT_EQ(Ticket::aktive(), vorher + 1);
    Ticket b("Rudi");
    EXPECT_EQ(b.nr(), a.nr() + 1); // fehlgeschlagenes Ticket verbraucht keine Nummer
}

TEST(Ticket, Kopie) {
    int vorher = Ticket::aktive();
    {
        Ticket a("Susi");
        Ticket b(a);
        EXPECT_EQ(b.nr(), a.nr());
        EXPECT_EQ(Ticket::aktive(), vorher + 2);
    }
    EXPECT_EQ(Ticket::aktive(), vorher);
}

static int zaehle_im_aufruf(Ticket t) { // Uebergabe als Kopie
    return Ticket::aktive() + 0 * t.nr();
}

TEST(Ticket, Wertparameter) {
    int vorher = Ticket::aktive();
    Ticket a("Susi");
    EXPECT_EQ(zaehle_im_aufruf(a), vorher + 2);
    EXPECT_EQ(Ticket::aktive(), vorher + 1);
}
