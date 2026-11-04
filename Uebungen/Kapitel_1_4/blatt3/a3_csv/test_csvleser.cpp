#include <fstream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

#include "gtest/gtest.h"
#include "CsvLeser.h"

using namespace std;

static_assert(!is_copy_constructible<CsvLeser>::value, "nicht kopierbar");
static_assert(!is_copy_assignable<CsvLeser>::value, "nicht zuweisbar");
static_assert(!is_convertible<string, CsvLeser>::value, "nicht implizit aus string");

static void schreibe(const string& name, const string& inhalt) {
    ofstream out(name);
    out << inhalt;
}

TEST(CsvLeser, NichtLesbar) {
    try {
        CsvLeser l("gibt_es_nicht.csv");
        FAIL() << "keine Ausnahme";
    } catch (const runtime_error& e) {
        EXPECT_STREQ(e.what(), "Datei nicht lesbar: gibt_es_nicht.csv");
    }
}

TEST(CsvLeser, Felder) {
    schreibe("t1.csv", "a;b;c\nx;;z\n");
    CsvLeser l("t1.csv");
    vector<string> f;
    ASSERT_TRUE(l.naechste(f));
    EXPECT_EQ(f, (vector<string>{"a", "b", "c"}));
    ASSERT_TRUE(l.naechste(f));
    EXPECT_EQ(f, (vector<string>{"x", "", "z"}));
    EXPECT_FALSE(l.naechste(f));
    EXPECT_EQ(f, (vector<string>{"x", "", "z"})); // am Ende unveraendert
}

TEST(CsvLeser, LeereZeilenUndNummern) {
    schreibe("t2.csv", "\neins\n\n\nzwei;\n");
    CsvLeser l("t2.csv");
    const CsvLeser& cl = l;
    vector<string> f;
    ASSERT_TRUE(l.naechste(f));
    EXPECT_EQ(f, (vector<string>{"eins"}));
    EXPECT_EQ(cl.zeile(), 2u);
    ASSERT_TRUE(l.naechste(f));
    EXPECT_EQ(f, (vector<string>{"zwei", ""}));
    EXPECT_EQ(cl.zeile(), 5u);
    EXPECT_EQ(cl.gelesen(), 2u);
}

TEST(CsvLeser, Trenner) {
    schreibe("t3.csv", "1,2;3\n");
    CsvLeser l("t3.csv", ',');
    EXPECT_EQ(l.trenner(), ',');
    vector<string> f;
    ASSERT_TRUE(l.naechste(f));
    EXPECT_EQ(f, (vector<string>{"1", "2;3"}));
}
