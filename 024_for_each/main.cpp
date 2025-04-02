// For-Each

#include <list>

#include <iostream>

// Works same as for each
template<typename T>
void printList(const std::list<T>& list)
{
	for (auto it = list.cbegin(); it != list.cend(); ++it)
	{
		std::cout << *it << '\n';
	}
}

int main()
{
	int a[]{ 0,1,2,3 };

	// Doesn't modify the original array
	for (int x : a)
	{
		x = 0;
	}

	// Now modifies the original array
	for (int& x : a)
	{
		x = 0;
	}
}