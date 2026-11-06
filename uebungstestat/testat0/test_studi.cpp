#include "Studi.h"
#include "alltest.h"

#include <string>

// Aufgabe 2: Tests 4 bis 10

TEST_F(AllTest, Standardkonstruktor) {
    Studi s;
    SuspendMemCheck smc;
    EXPECT_EQ(0, s.matnr());
    EXPECT_EQ("", s.vorname());
    EXPECT_EQ("", s.nachname());
    EXPECT_EQ(nullptr, s.get_image());
    EXPECT_EQ(0, s.get_image_size());
}

TEST_F(AllTest, Konstruktor) {
    Studi s(1234567, "Max", "Muster");
    SuspendMemCheck smc;
    EXPECT_EQ(1234567, s.matnr());
    EXPECT_EQ("Max", s.vorname());
    EXPECT_EQ("Muster", s.nachname());
    EXPECT_EQ(nullptr, s.get_image());
}

TEST_F(AllTest, set_matnr) {
    Studi s(1234567, "Max", "Muster");
    SuspendMemCheck smc;
    EXPECT_TRUE(s.set_matnr(7654321));
    EXPECT_EQ(7654321, s.matnr());
    EXPECT_FALSE(s.set_matnr(123456));      // 6-stellig
    EXPECT_FALSE(s.set_matnr(12345678));    // 8-stellig
    EXPECT_FALSE(s.set_matnr(-1234567));    // negativ
    EXPECT_EQ(7654321, s.matnr());          // alter Wert bleibt
}

TEST_F(AllTest, set_image) {
    Studi s(1234567, "Max", "Muster");
    char bild[4]{1, 2, 3, 4};
    s.set_image(bild, 4);
    bild[0] = 99;   // Aenderung am Original darf nicht durchschlagen
    SuspendMemCheck smc;
    EXPECT_EQ(4, s.get_image_size());
    ASSERT_NE(nullptr, s.get_image());
    EXPECT_NE(bild, s.get_image());
    EXPECT_EQ(1, s.get_image()[0]);
    EXPECT_EQ(4, s.get_image()[3]);
}

TEST_F(AllTest, set_image_ueberschreiben) {
    Studi s(1234567, "Max", "Muster");
    char bild1[3]{1, 2, 3};
    char bild2[5]{9, 8, 7, 6, 5};
    s.set_image(bild1, 3);
    s.set_image(bild2, 5);    // alter Speicher muss freigegeben werden
    SuspendMemCheck smc;
    EXPECT_EQ(5, s.get_image_size());
    ASSERT_NE(nullptr, s.get_image());
    EXPECT_EQ(9, s.get_image()[0]);
    EXPECT_EQ(5, s.get_image()[4]);
}

TEST_F(AllTest, Kopie) {
    Studi a(1234567, "Max", "Muster");
    char bild[4]{1, 2, 3, 4};
    a.set_image(bild, 4);
    Studi b{a};
    SuspendMemCheck smc;
    EXPECT_EQ(0, b.matnr());                 // Matrikelnummer wird nicht kopiert
    EXPECT_EQ("Max", b.vorname());
    EXPECT_EQ("Muster", b.nachname());
    EXPECT_EQ(4, b.get_image_size());
    ASSERT_NE(nullptr, b.get_image());
    EXPECT_NE(a.get_image(), b.get_image()); // eigener Speicher
    EXPECT_EQ(3, b.get_image()[2]);
    EXPECT_EQ(1234567, a.matnr());
}

TEST_F(AllTest, Kopie_ohne_Bild_und_Feld) {
    Studi a(1234567, "Max", "Muster");
    Studi b{a};
    SuspendMemCheck smc;
    EXPECT_EQ(nullptr, b.get_image());
    EXPECT_EQ(0, b.get_image_size());
    Studi* feld = new Studi[3];              // nicht initialisiert: Matnr 0 ok
    EXPECT_EQ(0, feld[1].matnr());
    delete[] feld;
}
