#include "calcMach.h"

int main() {
    auto calculator = createBasicCalculator();

    calculator.input_starting_value();

    calculator.push_command("MUL 123");
    calculator.push_command("ADD 1248141256664646");
    calculator.push_command("SUB 857823589230");
    calculator.push_command("MUL 224523");
    calculator.push_command("ADD 321");

    calculator.run();
}