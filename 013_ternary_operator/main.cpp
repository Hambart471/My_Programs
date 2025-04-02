// Ternary Operator

// The ternary operator is a shorthand for a simple if-else statement
// It follows the syntax:
// condition ? expression_if_true : expression_if_false;

#include <iostream>

int main()
{
	int a = 1;

	a > 0 ? std::cout << "a > 0\n"
		: a < 0 ? std::cout << "a < 0\n"
		: std::cout << "a == 0\n";
}