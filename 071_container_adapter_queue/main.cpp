// Similar to doubly linked list

// First In, First Out (FIFO) structure
// Only allows access to the front and back elements
// Uses a container internally (default: std::deque)
// std::vector cannot be used as a container (no push_front())

//     ---------------
// <-- (n)<->(n)<->(n) <--
//     ---------------

// circular queue doesn't delete the first element after extraction of it's
// value, it moves this element to the back

// priority queue

//     ---------------
// <-- (1)<->(2)<->(3) <--
//     ---------------

// priority addition
// priority is decided at the moment of adding
// first you add all ones then twos and then threes

//     ---------------------
// <-- (1)<->(1)<->(2)<->(3) (1) <--
//     ---------------------

// priority extraction
// you add all elements and then extract according to priorities
//         --------------
// <-- (1) (2)<->(3)<->(1) <--
//         --------------

#include <queue>

#include <list>
#include <deque>

#include <iostream>

int main()
{
	// Vector can't be the container for queue
	// Deque is the default container for queue
	std::queue<int> q;
	// Constructs in place
	q.emplace(0);
	int a = 1;
	// Copies value
	q.push(a);
	std::cout << "front() = " << q.front() << '\n';
	std::cout << "back() = " << q.back() << '\n';
	q.front() = 1;
	q.back() = 0;
	std::cout << "front() = " << q.front() << '\n';
	std::cout << "back() = " << q.back() << '\n';
	q.pop();
	std::cout << "size() = " << q.size() << '\n';
	std::cout << "empty() = " << q.empty() << '\n';
	q.front() = 2;
	std::queue<int> q2;
	q.swap(q2);
	std::cout << "front() = " << q2.front() << '\n';
	std::cout << "back() = " << q2.back() << '\n';
}