// Sizeof Operator

// The sizeof operator in C++ returns the size, in bytes, of a variable, data
// type, or data structure. It is a compile-time operator, which means it
// evaluates the size during compilation and not at runtime

#include <iostream>

int main()
{
	// Size of a single char
	std::cout << sizeof(char) << '\n';

	std::cout << '\n';
	const int SIZE = 26;
	char a[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		a[i] = 'A' + i;
		std::cout << a[i] << '\n';
	}
	// Total size of the array in bytes
	// Works only on static arrays (not pointers or dynamically allocated arrays)
	std::cout << sizeof(a) << '\n';

	std::cout << '\n';
	char a2[]{ 'A','B','C' };
	// Iterate using sizeof to determine array length
	for (int i = 0; i < sizeof(a2) / sizeof(a2[0]); ++i)
	{
		std::cout << a2[i] << '\b';
	}
}