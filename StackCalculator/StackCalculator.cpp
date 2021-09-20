// StackCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include <iostream>
#include "Stack.h"
#include "Calculator.h"

int main()
{
	char* input = (char*)calloc(256, sizeof(char));

	std::cin >> input;

	int result = Calculator::compute(input);
	std::cout << input << " = " << result << "\n";
}

