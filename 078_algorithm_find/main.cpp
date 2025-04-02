// Algorithm Find

#include <algorithm>
#include <vector>

#include <iostream>

class Person
{
public:
	Person(std::string name, double score) :
		name(name),
		score(score) {}

	// Functor for checking score > 180
	bool operator()(const Person& p) const
	{
		return p.score > 180;
	}

	std::string name;
	double score;
};

bool greaterThanZero(int value)
{
	return value > 0;
}

int main()
{
	std::vector<int> v{ 9,4,94,6,1,3,7 };

	// If element was not found, pointer is returned with the address pointing
	// after the last element
	auto result = std::find(v.begin(), v.end(), 94);

	if (result == v.end())
	{
		std::cout << "Not found\n";
	}
	else
	{
		std::cout << *result << '\n';
	}

	// find but can be with conditions
	auto result2 = std::find_if(v.begin(), v.end(), [](int a)
		{
			return a % 2 == 0;
		});

	std::cout << '\n';
	std::cout << *result2 << '\n';
	// find_if_not is the same but reversed

	std::vector<Person> people
	{
		Person("John",181),
		Person("Mary",30),
		Person("Jane",179),
		Person("Dylan",200),
		Person("Max",198),
		Person("Sasha",181),
		Person("Ben",50),
		Person("Ahmed",150),
	};
	// We can't use find because < > are not overloaded but we can use find_if

	// Using Person's operator() as predicate
	Person person{ "",0 }; // Create a Person object to use as a functor

	// std::find() doesn't work because Person has no operator==()
	auto it = std::find_if(people.begin(), people.end(), person);

	if (it != people.end())
	{
		std::cout << "\nFound: " << it->name << " with score " << it->score << '\n';
	}
	else
	{
		std::cout << "\nNo person found with score > 180\n";
	}
}