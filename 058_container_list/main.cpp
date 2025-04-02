// Doubly linked list

#include <list>

#include <iostream>

int main()
{
	// 1. list
	// 2. push_front()
	// 3. pop_front()
	// 4. push_back()
	// 5. pop_back()
	// 6. iterator
	// 7. begin()
	// 8. end()
	// 9. ++it
	// 10.advance()
	// 11.insert()
	// 12.erase()
	// 13.remove()
	// 14.sort()
	// 15.reverse()
	// 16.assign()
	// 17.size()
	// 18.unique()
	// 19.clear()
	// 20.cbegin()
	// 21.cend()
	
	// can't use []
	std::list<int> l{ 0,1 };
	l.push_front(-1);
	l.pop_front();
	l.push_back(2);
	l.pop_back();
	for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		std::cout << *it << '\n';
	}
	// it += 2 is not valid, but advance is
	auto it2 = l.begin();
	advance(it2, 1);
	// inserts new element before the iterator position
	l.insert(it2, 0);
	// Remove element at `it2`
	l.erase(it2);
	// removes the first element with the given value
	l.remove(0);
	l.sort();
	// reverse sort
	l.reverse();
	// delete everything and fill the list with 2 elements of value 3
	l.assign(2, 3);
	// copy another list
	std::list<int> l2;
	l2.assign(l.begin(), l.end());
	l.size();
	// deletes adjacent duplicate elements (sort first)
	l.unique();
	l.clear();
	// constant
	l.cbegin();
	l.cend();
}