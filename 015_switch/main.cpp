// Switch Statement

// Efficient for handling multiple distinct values
// instead of multiple if-else conditions
// Switch works with integral types (char, int, enum)

#include <iostream>

int main()
{
	char value = 'A';

	// Evaluates value and executes the matching case
	switch (value)
	{
	case 'A':
		std::cout << "Value: 'A'\n";
		// Prevents fall-through to other cases
		break;
	default:
		std::cout << "Value is not 'A'\n";
		break;
	}
}