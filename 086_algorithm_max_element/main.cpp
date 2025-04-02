// Algorithm Max Element

#include <algorithm>
#include <vector>

#include <iostream>

int main()
{
	std::vector<int> v{ 0,234,1,23,45,6,745 };
	auto result = max_element(v.begin(), v.end());
	std::cout << *result << '\n';
}