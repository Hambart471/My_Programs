// Inline Function

// The inline keyword suggests the compiler to replace function calls with the
// function body for performance optimization

// Inlining is a suggestion, not a guarantee

// Works well for small, frequently used functions

// Marking inline functions in headers avoids multiple definition errors
// when used in multiple files

#include <iostream>

inline int sum(int a, int b)
{
	return a + b;
}

int main()
{
	// The compiler may replace sum(1, 2) with 1 + 2, optimizing execution
	std::cout << sum(1, 2) << '\n';
}