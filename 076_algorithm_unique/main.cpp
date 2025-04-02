// Algorithm Unique

#include <algorithm>
#include <vector>

#include <iostream>

int main()
{
	int a[]{ 1,2,2,3,3,3,2,2,3,4 };
	// Unique shifts duplicates to the end and returns new logical end
	auto result = std::unique(std::begin(a), std::end(a));
	for (int x : a)
	{
		std::cout << x << '\n';
	}

	std::cout << '\n';
	std::for_each(std::begin(a), result, [](int x)
	{
		std::cout << x << '\n';
	});

	std::vector<int> a2{ std::begin(a), std::end(a) };
	auto result2 = unique(a2.begin(), a2.end());
	a2.erase(result2, a2.end());
	std::cout << '\n';
	for (int x : a2)
	{
		std::cout << x << '\n';
	}

	std::vector<int> a3;
	std::unique_copy(std::begin(a), std::end(a), back_inserter(a3));
	std::cout << '\n';
	for (int x : a3)
	{
		std::cout << x << '\n';
	}
}