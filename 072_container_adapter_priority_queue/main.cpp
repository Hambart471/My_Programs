// Priority Queue

// Max-Heap by Default
// Elements are ordered based on priority
// By default, the largest element is at the top (max-heap)

#include <queue>

#include <vector>
#include <list>
#include <deque>

#include <functional>

#include <iostream>

int main()
{
	// list can't be the container
	// vector is the default container
	std::priority_queue<int> pq;

	// this is not working
	//c = pq._Get_container();
	
	// shows the first element (largest)
	pq.top();

	// in STL elements added according to their priority
	// to change priority you need to use greater from functional library
	// Min-Heap
	std::priority_queue <int, std::vector <int>, std::greater <int>> pq2;
}