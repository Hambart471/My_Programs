// Hash Table with Duplicates

// Allows duplicate elements
// O(1) average complexity for insert, find, and erase
// Unordered storage (hashing-based)

#include <unordered_set>

#include <iostream>

int main()
{
    std::unordered_multiset<int> ums{ 1,2,1,1,2 };
    ums.erase(1); // Removes all instances of 1
}