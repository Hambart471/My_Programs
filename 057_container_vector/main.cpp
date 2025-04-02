// A dynamic array

#include <vector>

#include <iostream>

int main()
{
	// 1. vector
	// 2. push_back()
	// 3. size()
	// 4. capacity()
	// 5. reserve()
	// 6. shrink_to_fit()
	// 7. vector()
	// 8. vector(,)
	// 9. resize()
	// 10.resize(,)
	// 11.[]
	// 12.clear()
	// 13.empty()
	// 14.pop_back()
	// 15.at()

	std::vector<int> v{ 0,1 };
	v.push_back(2);
	v.size();
	v.capacity();
	// reserve() reserves capacity without changing size
	v.reserve(10);
	// shrink_to_fit() shrinks capacity to size
	v.shrink_to_fit();
	// vector(n) creates a vector of size n filled with zeros
	std::vector<int> v2(10);
	// vector(n, x) creates a vector of size n filled with x
	std::vector<int> v3(10, 1);
	// resize and fill with zeros
	v.resize(20);
	// or ones
	v.resize(20, 1);
	v[0];
	v.clear();
	// returns bool
	v.empty();
	v.pop_back();
	// safe and slow [], throws an exception
	try
	{
		v.at(10);
	}
	catch (std::out_of_range& e)
	{
		std::cout << '\n';
		std::cout << "Out of range exception: " << e.what() << '\n';
	}
}