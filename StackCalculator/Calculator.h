#pragma once
#include "Stack.h"
class Calculator
{
private:
	static bool isDigit(char c) {
		return c >= '0' && c <= '9';
	}

	static int readNumber(char* c, int &i) {
		int result = 0;
		int j = 0;

		while (c[i] != '\0' && isDigit(c[i]))
		{
			result *= 10;
			result += (c[i] - '0');
			i++;
			j++;
		}

		return result;
	}

	static int computeRestOfNumbers(Stack<int>* numbers) {
		int result = 0;

		while (!numbers->isEmpty()) {
			result += numbers->pop();
		}

		return result;
	}

public:
	static int compute(char* input) {
		Stack<char>* operators = new Stack<char>();
		Stack<int>* numbers = new Stack<int>;
		
		int i = 0;

		while (input[i] != '\0') {
			if (isDigit(input[i])) {
				int number = readNumber(input, i);
				numbers->push(number);
			}
			else {
				operators->push(input[i]);
				i++;
			}

			if (!operators->isEmpty() && operators->peek() == '*') {
				int nextNumber = readNumber(input, i);
				numbers->push(nextNumber * numbers->pop());
				operators->pop();
			}
		}

		return computeRestOfNumbers(numbers);
	}
};

