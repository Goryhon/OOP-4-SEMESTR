#pragma once

#include "stack.h"
#include "bigInt.h"
#include "dict.h"
#include "logger.h"
#include <iostream>
#include <string>
#include <sstream>


typedef bigInt (*func)(bigInt, bigInt);


class Calculator {
private:
    dict<func> commands;
    stack<std::pair<std::string, bigInt>> comms_stack;
    bigInt curr_value;
    ILogger *logger;

public:
    Calculator(ILogger *logger, bigInt start_value);

    void input_starting_value();

    void add_command(const std::string &name, func function);

    void push_command(const std::string &command);

    void run();

    bigInt get_curr_value();
};

bigInt sum(bigInt a, bigInt b);

bigInt sub(bigInt a, bigInt b);

bigInt mul(bigInt a, bigInt b);

Calculator createBasicCalculator();