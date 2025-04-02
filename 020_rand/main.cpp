// Rand Function

// The rand() function in C++ generates a pseudo-random integer between 0 and
// RAND_MAX, which is typically a large positive number defined in the <cstdlib>
// library. You can modify the randomness using the srand() function, which
// sets the seed for the random number generator

// time(nullptr) returns the current time as the number of seconds since the
// epoch (January 1, 1970), which changes every time the program is run

#include <ctime>

#include <iostream>

int main()
{
	std::cout << rand() << '\n';
	srand(time(nullptr));
	std::cout << rand() << '\n';
	// rand() % 10 gives a random number between 0 and 9
	std::cout << rand() % 10 << '\n';
	// rand() % 10 + 5 gives a random number between 5 and 14
	std::cout << rand() % 10 + 5 << '\n';
}