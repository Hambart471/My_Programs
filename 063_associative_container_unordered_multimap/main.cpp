// Hash-based key-value container
// (O(1) average time complexity)
// Allows duplicate keys (unlike std::unordered_map)
// No order guarantee (keys are unordered)
// Does NOT support operator[] or at() (because keys are not unique)

#include <unordered_map>

#include <iostream>

int main()
{
    // unordered_multimap
    std::unordered_multimap<int, std::string> umm;
    umm.emplace(7, "Keyboard");
    umm.emplace(7, "Keyboard");
    umm.emplace(7, "Processor");
    umm.emplace(7, "Keyboard");
    umm.emplace(7, "Processor");

    // Print the unordered_multimap
    std::cout << "Unordered Multimap:\n";
    for (const auto& e : umm)
    {
        std::cout << e.first << ": " << e.second << '\n';
    }
    // [] is not working in unordered_multimap
    // at() is not working in unordered_multimap

    auto it = umm.find(7);  // Returns iterator to any one of the key's values
    if (it != umm.end())
    {
    std::cout << it->first << ": " << it->second << '\n';
    }

    // Finding All Values for a Key
    auto range = umm.equal_range(7);  
    for (auto it = range.first; it != range.second; ++it)
    {
    std::cout << it->first << ": " << it->second << '\n';
    }
}