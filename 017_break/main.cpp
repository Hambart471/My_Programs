// Break Statement

// Useful for early exits from loops when a specific condition is met
// Works in switch statement, but doesn't in if statement

#include <iostream>

int main()
{
	for (int i = 0;; ++i)
	{
		std::cout << i << '\n';
		if (i == 10000)
		{
			break;
		}
	}
}