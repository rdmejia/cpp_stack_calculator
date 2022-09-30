#pragma once
#include "Stack.h"

#include <string.h>
#include <iostream>
#include <math.h>

using std::string;
using std::isdigit;
using std::cout;

class Calculator
{
private:
	Stack<double>* numbers = new Stack<double>();
	Stack<char>* operators = new Stack<char>();

    double read_number(string* input, int& i) {
        double result = 0;

        while (i != input->length() && isdigit(input->at(i)))
        {
            result = result * 10;
            result = result + (input->at(i) - '0');
            i++;
        }

        return result;
    }

    bool is_first_precedence(char op) {
        return op == '+' || op == '-';
    }

    bool is_second_precedence(char op) {
        return op == '*' || op == '/';
    }

    bool is_third_precedence(char op) {
        return op == '^';
    }

    bool is_higher_than_first_precedence(char op) {
        return is_second_precedence(op) || is_third_precedence(op);
    }

    bool is_higher_precedence(char op) {
        if (is_first_precedence(op)) {
            return !operators->is_empty();
        }

        if (is_second_precedence(op)) {
            return !operators->is_empty() && is_higher_than_first_precedence(*(operators->peek()));
        }

        return !is_third_precedence(op);
    }

    double compute(double n1, double n2, char op) {
        switch (op)
        {

        case '+':
            return n2 + n1;

        case '-':
            return n2 - n1;

        case '*':
            return n2 * n1;

        case '/':
            return n2 / n1;

        case '^':
            return pow(n2, n1);

        }

        return 0;
    }

    double handle_operator(string* input, int& i) {
        char op = input->at(i);
        double n1 = 0;
        double n2 = 0;

        if (!is_higher_precedence(op)) {
            operators->push(&op);
            i++;

            n2 = read_number(input, i);
            numbers->push(&n2);

            return compute_result(input, i);

        }

        n1 = *numbers->pop();
        n2 = *numbers->pop();

        double result = compute(n1, n2, *operators->pop());

        numbers->push(&result);
        operators->push(&op);
        i++;

        return compute_result(input, i);
    }

    double compute_stack(double previous_number, char previous_op) {
        if (numbers->get_size() == 1) {
            return compute(previous_number, *(numbers->pop()), previous_op);
        }

        double previous_result = compute_stack(*numbers->pop(), *operators->pop());

        return compute(previous_number, previous_result, previous_op);
    }

    double compute_stack() {
        return compute_stack(*numbers->pop(), *operators->pop());
    }

    double compute_result(string* input, int& i) {
        if (i == input->length()) {
            return compute_stack();
        }

        if (isdigit(input->at(i))) {
            double number = read_number(input, i);

            numbers->push(&number);

            return compute_result(input, i);
        }

        return handle_operator(input, i);
    }

public:
    double compute(string* input) {
        int i = 0;
        return compute_result(input, i);
    }

};

