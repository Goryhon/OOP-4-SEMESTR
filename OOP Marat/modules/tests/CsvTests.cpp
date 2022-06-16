#include "gtest/gtest.h"
#include "csv.h"

TEST(PARSER_TESTS, FILE) {
    csv parser;
    parser.parse("input.csv");

    EXPECT_EQ(parser.arr[0][0], "1997");
    EXPECT_EQ(parser.arr[0][1], "Ford");
    EXPECT_EQ(parser.arr[0][2], "E350");
    EXPECT_EQ(parser.arr[0][3], "\"ac, abs, moon\"");
    EXPECT_EQ(parser.arr[0][4], "3000.00");

    EXPECT_EQ(parser.arr[1][0], "1999");
    EXPECT_EQ(parser.arr[1][1], "Chevy");
    EXPECT_EQ(parser.arr[1][2], "\"Venture Extended Edition\"");
    EXPECT_EQ(parser.arr[1][3], "\"\"");
    EXPECT_EQ(parser.arr[1][4], "4900.00");

    EXPECT_EQ(parser.arr[2][0], "1996");
    EXPECT_EQ(parser.arr[2][1], "Jeep");
    EXPECT_EQ(parser.arr[2][2], "Grand Cherokee");
    EXPECT_EQ(parser.arr[2][3], "\"MUST SELL! air, moon roof, loaded\"");
    EXPECT_EQ(parser.arr[2][4], "4799.00");
}
