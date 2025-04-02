// Recursion

// factorial(5) -> 5 * factorial(4)
// factorial(4) -> 4 * factorial(3)
// factorial(3) -> 3 * factorial(2)
// factorial(2) -> 2 * factorial(1)
// factorial(1) -> 1 (Base case)

// Base case prevents infinite recursion

#include <iostream>

int factorial(int a)
{
	if (a == 1)
	{
		return 1;
	}
	return a * factorial(a - 1);
}

int main()
{
	int a = 5;
	std::cout << factorial(a) << '\n';
}