#include "bigInt.h"
#include "gtest/gtest.h"

TEST(BIG_INT_TESTS, INVALID_VALUE) {
    EXPECT_EQ("0", bigInt("").getVal());
    EXPECT_EQ("0", bigInt(";lajl;a;ja;j43434").getVal());
    EXPECT_EQ("0", bigInt("aaaaaaaaaaaaahhhh").getVal());
    EXPECT_EQ("0", bigInt("--3353").getVal());
    EXPECT_EQ("0", bigInt("1234-5678").getVal());
    EXPECT_EQ("0", bigInt("12345678-").getVal());
}

TEST(BIG_INT_TESTS, GET_VALUE) {
    EXPECT_EQ("0", bigInt("0000000000").getVal());
    EXPECT_EQ("999", bigInt("0000999").getVal());
    EXPECT_EQ("1337", bigInt("1337").getVal());
    EXPECT_EQ("859", bigInt("-859").getVal());
    EXPECT_EQ("4564", bigInt("-0000004564").getVal());
    EXPECT_EQ("7821457821459023980508349809", bigInt("7821457821459023980508349809").getVal());
}

TEST(BIG_INT_TESTS, NEGATIVE) {
    EXPECT_TRUE(bigInt("-0000000000").isNeg());
    EXPECT_TRUE(bigInt("-0000999").isNeg());
    EXPECT_TRUE(bigInt("-859").isNeg());
    EXPECT_TRUE(bigInt("-1345145126134614636243625723562141").isNeg());
    EXPECT_TRUE((bigInt("-4343412") + bigInt("-43434")).isNeg());
}

TEST(BIG_INT_TESTS, SUM) {
    bigInt a("100");
    bigInt b("1000");
    bigInt c = a + b;
    EXPECT_EQ(c.getVal(), "1100");

    a = bigInt("100");
    b = bigInt("-100");
    c = a + b;
    EXPECT_EQ(c.getVal(), "0");

    a = bigInt("-1040");
    b = bigInt("-50");
    c = a + b;
    EXPECT_EQ(c.getVal(), "1090");

    a = bigInt("-55");
    b = bigInt("5");
    c = a + b;
    EXPECT_EQ(c.getVal(), "50");

    a = bigInt("8128350812501238902578013258700357820828135823597803105");
    b = bigInt("870123780325780312578152781597235763275735932597297597");
    c = a + b;
    EXPECT_EQ(c.getVal(), "8998474592827019215156166040297593584103871756195100702");
}

TEST(BIG_INT_TESTS, SUB) {
    bigInt a("100");
    bigInt b("1000");
    bigInt c = a - b;
    EXPECT_EQ(c.getVal(), "900");

    a = bigInt("100");
    b = bigInt("-50");
    c = a - b;
    EXPECT_EQ(c.getVal(), "150");

    a = bigInt("-139");
    b = bigInt("11");
    c = a - b;
    EXPECT_EQ(c.getVal(), "150");

    a = bigInt("-930");
    b = bigInt("-25");
    c = a - b;
    EXPECT_EQ(c.getVal(), "905");

    a = bigInt("125780950713280753829050982319050132059800158");
    b = bigInt("01723508912350912387109529352845025812082352135");
    c = a - b;
    EXPECT_EQ(c.getVal(), "1597727961637631633280478370525975680022551977");
}

TEST(BIG_INT_TESTS, MUL) {
    bigInt a("100");
    bigInt b("1000");
    bigInt c = a * b;
    EXPECT_EQ(c.getVal(), "100000");

    a = bigInt("532");
    b = bigInt("-10");
    c = a * b;
    EXPECT_EQ(c.getVal(), "5320");

    a = bigInt("-12");
    b = bigInt("-20");
    c = a * b;
    EXPECT_EQ(c.getVal(), "240");

    a = bigInt("-153");
    b = bigInt("275");
    c = a * b;
    EXPECT_EQ(c.getVal(), "42075");

    a = bigInt("780109835087132587901359780092109509");
    b = bigInt("000000012358012308573120858872587935980");
    c = a * b;
    EXPECT_EQ(c.getVal(), "9640606944045731992412986416688629630772361343173999252742441233820");

    a = bigInt("870445870105810895089");
    b = bigInt("0");
    c = a * b;
    EXPECT_EQ(c.getVal(), "0");

    a = bigInt("0");
    b = bigInt("2149124");
    c = a * b;
    EXPECT_EQ(c.getVal(), "0");

    a = bigInt("0");
    b = bigInt("-2149124");
    c = a * b;
    EXPECT_EQ(c.getVal(), "0");
}
