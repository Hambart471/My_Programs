// Algorithm Min Element

#include <algorithm>
#include <vector>

#include <iostream>

int main()
{
	std::vector<int> v{ 0,234,1,23,45,6,745 };
	auto result = min_element(v.begin(), v.end());
	std::cout << *result << '\n';
	auto result2 = minmax_element(v.begin(), v.end());
	std::cout << *result2.first << '\n'; // Minimum
	std::cout << *result2.second << '\n'; // Maximum
}