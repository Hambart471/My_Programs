// Iterators

#include <vector>

#include <iostream>

int main()
{
	std::vector<int> v{ 1,9,44,422,676,78 };
	std::vector<int>::iterator it;
	// Pointer to the first element
	it = v.begin();
	// Outputs: 1 (First element in vector)
	std::cout << *it << '\n';
	// Modifies the first element to 2
	*it = 2;
	std::cout << *it << '\n';
	++it;
	// Outputs: 9 (Second element in vector)
	std::cout << *it << '\n' << '\n';

	for (std::vector<int>::iterator it2 = v.begin(); it2 != v.end(); ++it2)
	{
		std::cout << *it2 << '\n';
	}
	std::cout << '\n';

	// const_iterator prevents modification of the vector elements during iteration
	for (std::vector<int>::const_iterator it2 = v.begin(); it2 != v.end(); ++it2)
	{
		std::cout << *it2 << '\n';
	}
	std::cout << '\n';

	// The cbegin() and cend() methods return constant iterators
	for (auto it2 = v.cbegin(); it2 != v.cend(); ++it2)
	{
		std::cout << *it2 << '\n';
	}
	std::cout << '\n';

	// You can iterate backwards using reverse iterators (rbegin() and rend())
	for (std::vector<int>::reverse_iterator it2 = v.rbegin(); it2 != v.rend(); ++it2)
	{
		std::cout << *it2 << '\n';
	}
	std::cout << '\n';

	// advance(it, 1) moves the iterator it forward by one position
	it = v.begin();
	advance(it, 1);
	std::cout << *it << '\n';
	std::cout << '\n';

	// Insert '7' at the position of 'it' and move everything else
	v.insert(it, 7);
	it = v.begin();
	advance(it, 1);
	std::cout << *it << '\n';

	// Erase the element at position 'it'
	it = v.begin();
	advance(it, 1);
	v.erase(it);
	it = v.begin();
	advance(it, 1);
	std::cout << *it << '\n';
	std::cout << '\n';

	// Erase elements from ['it' to 'it + 2')
	v.erase(it, it + 2);
	for (auto e : v)
		std::cout << e << '\n';
}