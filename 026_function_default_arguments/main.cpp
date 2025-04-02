// Default Function Arguments

// Default values must be defined in the function declaration
// (not in the definition if separate)

#include <iostream>

// The parameter a defaults to 1 if not provided
void myFunction(int a = 1)
{
	std::cout << a << '\n';
}

int main()
{
	// Calls myFunction() without arguments
	// If an argument isn't passed, the default value (1) is used
	myFunction();
}