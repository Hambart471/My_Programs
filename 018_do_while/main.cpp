// Do-While Loop

// Executes at least once, even if the condition is false initially

#include <iostream>

int main()
{
	char value = 'A';

	// Prints characters from 'A' to 'Z'
	do
	{
		// Prints the current value, then increments it
		std::cout << value++ << '\n';
	} while (value <= 'Z');
}