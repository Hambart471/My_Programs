// Unordered Map is a hash-based key-value container

// (O(1) average time complexity)
// Unique keys only (use std::unordered_multimap for duplicates)
// No order guarantee (keys are unordered)

#include <unordered_map>

#include <iostream>

int main()
{
    // 1. pair
    // 2. make_pair()
    // 3. unordered_map
    // 4. insert()
    // 5. emplace()
    // 6. find()
    // 7. end()
    // 8. []
    // 9. erase()
    // 10.at()
    // 11.unordered_multimap

    // 1. pair
    std::pair<int, std::string> p(1, "Phone");
    std::cout << p.first << '\n';
    std::cout << p.second << '\n' << '\n';

    // 2. make_pair()
    auto a = std::make_pair(4, "Microphone");
    std::cout << a.first << '\n';
    std::cout << a.second << '\n';

    // 3. unordered_map
    std::unordered_map<int, std::string> um{ {2, "Monitor"} };

    // 4. insert() takes an already constructed pair
    um.insert(p);

    // Or constructs it before calling insert
    um.insert({ 3, "Mouse" });
    um.insert(std::pair<int, std::string>(5, "Speakers"));
    um.insert(std::make_pair(4, "Microphone"));
    // insert is used when you already have a pair or want to insert multiple
    // elements at once

    // 5. emplace() constructs the element directly inside the container
    // used for efficiency, especially with complex objects
    um.emplace(6, "Laptop");

    // 6. find() a key and return an iterator to it
    std::cout << '\n';
    std::unordered_map<int, std::string>::iterator it = um.find(1);

    // 7. If the key is not found, find() returns an iterator to end() - past
    // the last element
    if (it != um.end())
    {
        std::cout << it->first << '\n';
        std::cout << it->second << '\n';
    }
    else
    {
        std::cout << "Key not found\n";
    }

    // unordered_map stores only unique keys
    um.emplace(7, "Keyboard");
    um.emplace(7, "Keyboard");
    um.emplace(7, "Processor");
    um.emplace(7, "Keyboard");
    um.emplace(7, "Processor");

    // Print the unordered_map
    std::cout << '\n';
    std::cout << "Unordered Map:\n";
    for (auto e : um)
    {
        std::cout << e.first << ": " << e.second << '\n';
    }

    // 8. Access value by key (inserts if missing)
    um[7];

    // But prints only the value
    std::cout << '\n';
    std::cout << "um[7] = " << um[7] << '\n';

    // You can change the value
    um[7] = "Chair";
    std::cout << '\n';
    std::cout << "um[7] = " << um[7] << '\n';

    // You can add a new element
    um[8] = "Videocard";
    std::cout << '\n';
    std::cout << "um[8] = " << um[8] << '\n';

    // Print the unordered_map
    std::cout << '\n';
    std::cout << "Unordered Map:\n";
    for (auto e : um)
    {
        std::cout << e.first << ": " << e.second << '\n';
    }

    // you can use at() for more safety but it is slower
    um.at(8) = "TV";

    // 9. You can delete an element
    um.erase(7);

    // 10.if there is no such key, method at() will throw an exception
    try
    {
        // Throws std::out_of_range if key is missing
        um.at(9) = "Calendar";
    }
    catch (std::exception& e)
    {
        std::cout << '\n';
        std::cout << "Exception: " << e.what() << '\n';
    }

    // methods emplace() and insert() return a pair of iterator and bool
    // if failed, bool is false but the iterator does not point to end(),
    // it still points to the element
    auto it2 = um.emplace(8, "Memory");
    // auto it2 = um.insert({ 8, "Memory" });
    std::cout << '\n';
    if (it2.second)
    {
        std::cout << it2.first->first << ": " << it2.first->second << '\n';
    }
    else
    {
        std::cout << "Failed to emplace\n";
        std::cout << it2.first->first << ": " << it2.first->second << '\n';
    }

    it2 = um.emplace(9, "Memory");
    // it2 = um.insert({ 9, "Memory" });
    std::cout << '\n';
    if (it2.second)
    {
        std::cout << it2.first->first << ": " << it2.first->second << '\n';
    }
    else
    {
        std::cout << "Failed to emplace\n";
        std::cout << it2.first->first << ": " << it2.first->second << '\n';
    }

    // Print the unordered_map
    std::cout << '\n';
    std::cout << "Unordered Map:\n";
    for (const auto& e : um)
    {
        std::cout << e.first << ": " << e.second << '\n';
    }
}