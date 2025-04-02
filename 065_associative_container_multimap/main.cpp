// Ordered, allows duplicate keys, no operator[] or at()
// Sorted by keys (by default, uses std::less<Key>)

#include <map>

#include <iostream>

int main()
{
	std::multimap<int, std::string> mm;
	mm.emplace(7, "Keyboard");
	mm.emplace(7, "Keyboard");
	mm.emplace(7, "Processor");
	mm.emplace(7, "Keyboard");
	mm.emplace(7, "Processor");

	// Print the multimap
	std::cout << "Multimap:\n";
	for (const auto& e : mm)
	{
		std::cout << e.first << ": " << e.second << '\n';
	}
	// Find All Values for a Key
	auto range = mm.equal_range(7);
	for (auto it = range.first; it != range.second; ++it)
	{
    std::cout << it->first << ": " << it->second << '\n';
	}
	mm.erase(7);  // Removes all elements with key 7
}