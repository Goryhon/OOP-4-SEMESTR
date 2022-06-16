#include "calcMach.h"

Calculator::Calculator(ILogger *logger, bigInt start_value) {
    this->logger = logger;
    this->commands = dict<func>();
    this->comms_stack = stack<std::pair<std::string, bigInt>>();
    this->curr_value = start_value;
}

void Calculator::input_starting_value() {
    std::cout << "Enter starting value: \n";
    std::string input;
    std::getline(std::cin, input);
    this->curr_value = bigInt(input);
}

void Calculator::add_command(const std::string &name, func function) {
    this->commands[name] = function;
}

void Calculator::push_command(const string &command) {
    std::string comm;
    std::string num;
    std::stringstream ss;
    ss << command;
    ss >> comm >> num;
    if (!this->commands.has(comm)) {
        this->logger->error("Command not found");
        throw std::runtime_error("Command not found");
    }
    this->comms_stack.push({comm, bigInt(num)});
}

void Calculator::run() {
    this->logger->info("Start: " + this->curr_value.getVal());
    std::pair<std::string, bigInt> command;
    while (this->comms_stack.length() != 0) {
        command = this->comms_stack.pop();
        this->logger->info("Operation " + command.first + " " + command.second.getVal());
        this->curr_value = this->commands[command.first](this->curr_value, command.second);
        this->logger->info("Result: " + this->curr_value.getVal());
    }
}

bigInt Calculator::get_curr_value() {
    return this->curr_value;
}

bigInt sum(bigInt a, bigInt b) {
    return a + b;
}

bigInt sub(bigInt a, bigInt b) {
    return a - b;
}

bigInt mul(bigInt a, bigInt b) {
    return a * b;
}

Calculator createBasicCalculator() {
    LoggerCMDFact logger_fact;
    Calculator calculator(logger_fact.create(), bigInt("0"));

    calculator.add_command("ADD", sum);
    calculator.add_command("SUB", sub);
    calculator.add_command("MUL", mul);

    return calculator;
}