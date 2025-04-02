// Static Array

#include <array>

#include <iostream>

int main()
{
	// 1. array
	// 2. []
	// 3. at()
	// 4. size()
	// 5. fill()
	// 6. front()
	// 7. back()
	// 8. ==, !=, <, >
	
	// must define size at compile time
	std::array<int, 10> a{ 0 };
	a[0];
	// safe, slow and throws exception
	a.at(0);
	a.size();
	a.fill(1);
	// first element
	a.front();
	a.back();
	std::array<int, 10> a2{ 0,1 };
	// works for other containers as well as !=, < and >
	// if element type supports them
	std::cout << (a == a2) << '\n';
}