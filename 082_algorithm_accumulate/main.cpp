// Algorithm Accumulate

#include <numeric>
#include <vector>
#include <string>

#include <iostream>

int main()
{
	std::vector<int> v{ 2,3,4 };

	std::cout << accumulate(v.begin(), v.end(), 0) << '\n';

	// In case we would like to change v to something else
	int v2[]{ 2,3,4 };
	std::cout << std::accumulate(std::begin(v2), std::end(v2), 0) << '\n';

	std::cout << std::accumulate(std::begin(v2), std::end(v2), 1, [](int a, int b)
		{
			return a * b;
		}) << '\n';

	std::cout << std::accumulate(std::begin(v2), std::end(v2), 0, [](int a, int b)
		{
			if (b % 2 == 0)
			{
				return a + b;
			}
			else
			{
				return a;
			}
		}) << '\n';

	std::cout << accumulate(next(begin(v)), end(v), std::to_string(v[0]), [](std::string a, int b)
		{
			return a + " " + std::to_string(b);
		}) << '\n';
}