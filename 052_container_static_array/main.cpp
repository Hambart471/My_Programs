// Static Array

#include <iostream>

void printArray(const char* const a, const int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << *(a + i) << '\n';
		// same as
		//std::cout << a[i] << '\n';
	}
}

int main()
{
	// Static arrays have a fixed size (determined at compile time)

	// 1. Static array declaration
	// 2. Default initialization
	// 3. Implicit size calculation
	// 4. Partial initialization
	// 5. Const size

	// 1. Uninitialized (contains garbage values)
	char a[1];
	// 2. Zero-initialization sets all elements to 0 ('\0' for char)
	char a2[1]{};
	// 3. Size inferred from initializer list
	char a3[]{ 'a' };
	// 4. First element initialized, fill remaining element with default value
	char a4[2]{ 'a' };
	// 5. Usually, a constant is used for size
	const int SIZE = 1;
	char a5[SIZE];

	std::cout << a3[0] << '\n';
	std::cout << 0[a3] << '\n';

	printArray(a5, SIZE);
}