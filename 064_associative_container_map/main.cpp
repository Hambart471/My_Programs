// Red-Black Tree. Ordered, unique keys, O(log n) operations
// Sorted by keys (by default, uses std::less<Key>)

#include <map>

#include <iostream>

int main()
{
    // 1. pair
    // 2. make_pair()
    // 3. map
    // 4. insert()
    // 5. emplace()
    // 6. find()
    // 7. end()
    // 8. []
    // 9. at()
    // 10.erase()

	// 1. pair
	std::pair<int, std::string> p(1, "Phone");
	std::cout << p.first << '\n';
	std::cout << p.second << '\n' << '\n';

	// 2. make_pair()
	auto a = std::make_pair(4, "Microphone");
	std::cout << a.first << '\n';
	std::cout << a.second << '\n' << '\n';

	// 3. map
	std::map<int, std::string> m{ {2,"Monitor"} };

	// 4. insert() takes an already constructed pair
	m.insert(p);

	// Or constructs it before calling insert
	m.insert({ 3,"Mouse" });
	m.insert(std::pair<int, std::string>(5, "Speakers"));
	m.insert(std::make_pair(4, "Microphone"));
	// insert is used when you already have a pair or want to insert multiple
	// elements at once

	// 5. emplace() constructs the element directly inside the container
	// used for efficiency, especially with complex objects
	m.emplace(6, "Laptop");

	// 6. find() a key and return an iterator to it
	std::map<int, std::string>::iterator it = m.find(1);

	// 7. If the key is not found, find() returns an iterator to end() - past
	// the last element
	if (it != m.end())
	{
		std::cout << it->first << '\n';
		std::cout << it->second << '\n';
	}
	else
	{
		std::cout << "Key not found\n";
	}

	// Map stores only unique keys
	m.emplace(7, "Keyboard");
	m.emplace(7, "Keyboard");
	m.emplace(7, "Processor");
	m.emplace(7, "Keyboard");
	m.emplace(7, "Processor");

	// Print the map
	for (const auto& e : m)
	{
		std::cout << e.first << ": " << e.second << '\n';
	}

	// 8. [] takes a key and returns a pair it there is one
	m[7];

	// But prints only the value
	std::cout << "m[7] = " << m[7] << '\n';

	// You can change the value
	m[7] = "Chair";
	std::cout << "m[7] = " << m[7] << '\n';

	// You can add a new element
	m[8] = "Videocard";
	std::cout << "m[8] = " << m[8] << '\n';

	// 9. You can use at() for more safety but it is slower
	m.at(8) = "TV";

	// 10. You can delete an element
	m.erase(7);

	// If there is no such key, method at() will throw an exception
	try
	{
		m.at(9) = "Calendar";
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	// Methods emplace() and insert() return a pair of iterator and bool
	// if failed, bool is false but the iterator does not point to end(), it
	// still points to the element
	auto it2 = m.emplace(8, "Memory");
	//auto it2 = m.insert({ 8, "Memory" });
	if (it2.second)
	{
		std::cout << it2.first->first << ": " << it2.first->second << '\n';
	}
	else
	{
		std::cout << "Failed to emplace\n";
		std::cout << it2.first->first << ": " << it2.first->second << '\n';
	}

	it2 = m.emplace(9, "Memory");
	//it2 = m.insert({ 9, "Memory" });
	if (it2.second)
	{
		std::cout << it2.first->first << ": " << it2.first->second << '\n';
	}
	else
	{
		std::cout << "Failed to emplace\n";
		std::cout << it2.first->first << ": " << it2.first->second << '\n';
	}
}