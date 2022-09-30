// StackCalculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include <iostream>
#include <string.h>
#include "Stack.h"
#include "Calculator.h"

int main()
{
	string input;

	std::cin >> input;

	Calculator *calculator = new Calculator();

	double result = calculator->compute(&input);
	std::cout << input << " = " << result << "\n";
}

