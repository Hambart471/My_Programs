// Global Variable

// Global variables persist across functions
// Local function parameters shadow global variables

#include <iostream>

// Default initialized to 0
int a;

// Function modifying global variable
void increment()
{
	++a;
}

// Modifies only the local copy, not the global a
void increment2(int a)
{
	++a;
}

int main()
{
	// Default global value
	std::cout << a << '\n';
	increment();
	// Global 'a' incremented
	std::cout << a << '\n';
	increment2(a);
	// Doesn't modify global a
	std::cout << a << '\n';
}