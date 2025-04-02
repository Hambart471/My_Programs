// Binary Search Tree with Duplicates

// Sorted (ascending by default)
// Allows duplicate elements
// O(log N) complexity for insert, find, and erase

#include<set>

#include<iostream>

int main()
{
	std::multiset<int> ms{ 1,2,1,1,2,3 };

	// First occurrence of 1
	auto it2 = ms.lower_bound(1);

	// upper_bound finds the next element after the last 1
	auto it3 = ms.upper_bound(1);

	// returns the range from lower_bound to upper_bound
	auto it4 = ms.equal_range(1);

	for (auto i = it4.first; i != it4.second; ++i)
	{
		std::cout << *i << '\n';
	}
}