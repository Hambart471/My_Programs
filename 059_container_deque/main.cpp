// Double-ended queue

//     ---------------
// <-> (n)<->(n)<->(n) <->
//     ---------------

// sometimes can be

//     ---------------
// <-- (n)<->(n)<->(n) <->
//     ---------------

// or

//     ---------------
// --> (n)<->(n)<->(n) <->
//     ---------------

// STL deque is dobly linked list of dynamic arrays

//     ---------------------------------
// <-> { n,n,n }<->{ n,n,n }<->{ n,n,n } <->
//     ---------------------------------

#include <deque>

#include <iostream>

int main()
{
	// 1. deque
	// 2. push_back()
	// 3. push_front()
	// 4. pop_back()
	// 5. pop_front()
	// 6. []
	// 7. at()
	// 8. size()
	// 9. empty()
	// 10.clear()
	// 11.insert()
	// 12.erase()
	// 13.iterator
	// 14.begin()
	// 15.end()
	// 16.++it, --it
	// 17.front()
	// 18.back()

	std::deque<int> d{ 0 };
	d.push_back(1);
	d.push_front(2);
	// fast random access unlike list
	d[0];
	std::deque<int>::iterator it = d.begin();
	++it;
	--it;
}