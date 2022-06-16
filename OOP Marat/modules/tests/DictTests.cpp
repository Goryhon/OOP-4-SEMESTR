#include "gtest/gtest.h"
#include "dict.h"

TEST(DICT_TESTS, CHECK_VALUES) {
    dict<int> d;
    d["A"] = 777;
    d["B"] = 355;
    d["Karrr"] = 45245;

    EXPECT_EQ(d["A"], 777);
    EXPECT_EQ(d["B"], 355);
    EXPECT_EQ(d["Karrr"], 45245);
}

TEST(DICT_TESTS, BORDERS_OVERFLOW) {
    dict<int> d(3, 5);
    d["A"] = 777;
    d["B"] = 355;
    d["Karrr"] = 45245;
    d["Uh oh"] = 75;
    d["Do I exist?"] = 404;

    EXPECT_EQ(d["A"], 777);
    EXPECT_EQ(d["B"], 355);
    EXPECT_EQ(d["Karrr"], 45245);
    EXPECT_EQ(d["Uh oh"], 75);
    EXPECT_EQ(d["Do I exist?"], 404);
}