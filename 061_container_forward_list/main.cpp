// Singly linked list

#include <forward_list>

#include <iostream>

int main()
{
	// 1. forward_list
	// 2. iterator
	// 3. begin()
	// 4. ++it
	// 5. insert_after()
	// 6. erase_after()
	// 7. before_begin()
	// 8. push_front()
	// 9. pop_front()
	// 10.remove(1); // Remove all occurrences of 1
	// 11.sort()
	// 12.reverse()
	// 13.unique()
	// 14.clear()

	std::forward_list<int> fl{ 0 };
	std::forward_list<int>::iterator it = fl.begin();
	// --it isn't valid
	++it;
	// insert after instead of push_back
	fl.insert_after(it, 1);
	fl.erase_after(it);
	//to use insert_after if we need it
	it = fl.before_begin();
}