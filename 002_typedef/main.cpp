// Typedef Keyword

// Used to create an alias for an existing type
// This improves code readability and simplifies complex type declarations

#include <iostream>
#include <vector>

typedef std::vector<int> int_vector;
// This is preferred in modern C++ because it is more flexible
// (e.g., supports templates)
//using int_vector = std::vector<int>;

int main()
{
	std::vector<int> v;
	int_vector v1;
}