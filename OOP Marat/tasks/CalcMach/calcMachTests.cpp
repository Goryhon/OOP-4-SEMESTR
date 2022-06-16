#include "gtest/gtest.h"
#include "calcMach.h"

TEST(CALC_MACHINE_TEST, COMMAND_NOT_EXIST) {
    auto calculator = createBasicCalculator();

    calculator.push_command("ADD 51535");
    EXPECT_ANY_THROW(
            calculator.push_command("+ 1")
    );

}

TEST(CALC_MACHINE_TEST, INCORRECT_INPUT_NUMBER) {
    auto calculator = createBasicCalculator();

    calculator.push_command("ADD pro100aboba");

    EXPECT_EQ("0", calculator.get_curr_value().getVal());

}

TEST(CALC_MACHINE_TEST, CORRECT_INPUT) {
    auto calculator = createBasicCalculator();

    calculator.push_command("MUL 123");
    calculator.push_command("ADD 1248141256664646");
    calculator.push_command("SUB 857823589230");
    calculator.push_command("MUL 224523");
    calculator.push_command("ADD 321");

    calculator.run();

    EXPECT_EQ("153415871133117777", calculator.get_curr_value().getVal());
}
