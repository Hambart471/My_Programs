// Similar to a singly linked list, but we only work with the top element
// when we delete it we recieve it's value

//     ---------------
// <-> (n)<->(n)<->(n)|
//     ---------------

// Last In, First Out (LIFO) structure
// Only allows access to the top element
// Uses a container internally (default: std::deque)

#include <stack>

#include <vector>
#include <list>
#include <deque>

#include <iostream>

int main()
{
	std::stack<int> s;
	// copies value
	s.push(0);
	s.pop();
	// constructs directly in place
	s.emplace(1);
	s.size();
	// returns bool
	s.empty();
	// shows what is at top
	s.top();
	while (!s.empty())
	{
		std::cout << s.top() << '\n';
		s.pop();
	}
	// deque is used by default
	// s._Get_container() is not standard and should not be used!
	auto c = s._Get_container();
	// you can work with c as a regular deque
	std::cout << c[0] << '\n';
	// change default container
	std::stack<int, std::vector<int>> sv;
}