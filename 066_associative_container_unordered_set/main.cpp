// Hash table

// O(1) average complexity for insert, find, and erase
// No duplicate elements allowed
// Uses hashing, elements are not sorted

#include <unordered_set>

#include <iostream>

int main()
{
    std::unordered_set<int> us{ 5 };
    us.insert(0);
    // find() returns an iterator to the element or end() if not found
    if (us.find(0) != us.end())
    {
        std::cout << "Element exists\n";
    }
    else
    {
        std::cout << "Element doesn't exist\n";
    }
    // count() returns 1 if the element exists, otherwise 0
    if (us.count(5))
    {
        std::cout << "5 is in the set\n";
    }
    // erase() removes an element, returns 1 if removed, 0 if not found
    if (us.erase(0))
    {
        std::cout << "Element deleted\n";
    }
    else
    {
        std::cout << "Element was not deleted\n";
    }

    // bucket_count() shows the number of buckets
    std::cout << "Bucket count: " << us.bucket_count() << '\n';

    // load_factor() gives the ratio of elements to buckets
    std::cout << "Load factor: " << us.load_factor() << '\n';
}