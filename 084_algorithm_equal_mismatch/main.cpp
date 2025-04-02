// Algorithm Equal Mismatch

#include <algorithm>
#include <vector>

#include <iostream>

int main()
{
	int a[]{ 11,3,4,5,7,10 };
	std::vector<int> a2{ 10,3,4,5,7,11 };
	std::sort(std::begin(a), std::end(a));
	std::sort(std::begin(a2), std::end(a2));
	std::cout << std::equal(std::begin(a), std::end(a), std::begin(a2), std::end(a2)) << '\n';
	
	int a3[]{ 1,3,4,5,7,10 };
	std::vector<int> a4{ 2,3,4,5,7,11 };
	// std::mismatch(first1, last1, first2) compares two ranges
	// element by element and returns a pair of iterators
	auto result = std::mismatch(std::begin(a3), std::end(a3), std::begin(a4), std::end(a4));
	std::cout << *result.first << " " << *result.second << '\n';
	if (result.first == std::end(a3) && result.second == std::end(a4))
	{
		std::cout << "+\n";
	}
	else
	{
		std::cout << "-\n";
	}
}