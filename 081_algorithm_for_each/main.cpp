// Algorithm For Each

#include <algorithm>

#include <iostream>

int main()
{
	int a[]{ 1,2,3,4,5 };

	std::for_each(std::begin(a), std::end(a), [](int a)
		{
			std::cout << a << '\n';
		});

	std::cout << '\n';
	std::for_each(std::begin(a), std::end(a), [](const int& a)
		{
			std::cout << a << '\n';
		});

	std::cout << '\n';
	for (int x : a)
	{
		std::cout << x << '\n';
	}

	std::cout << '\n';
	for (const int& x : a)
	{
		std::cout << x << '\n';
	}
}