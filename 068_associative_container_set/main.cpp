// Binary Search Tree

// Sorted (ascending by default)
// O(log N) complexity for insert, find, and erase
// Only unique elements

#include<set>

#include<iostream>

int main()
{
	std::set<int> s{ 5 };
	s.insert(0);
	// You cannot modify elements in a set directly
	std::set<int>::iterator it = s.find(0);
	// if the element is not found, find() returns an iterator to end()
	// (past the last element)
	if (s.find(1) != s.end())
	{
		std::cout << "Element exists\n";
	}
	else
	{
		std::cout << "Element doesn't exist\n";
	}
	// erase() returns 0 if the element was not fount, otherwise 1
	if (s.erase(1))
	{
		std::cout << "Element deleted\n";
	}
	else
	{
		std::cout << "Element was not deleted\n";
	}
}