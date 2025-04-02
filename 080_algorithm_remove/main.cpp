// Algorithm Remove

#include <algorithm>
#include <vector>

#include <iostream>

class Person
{
public:
	Person(std::string name, double score) :
		name(name),
		score(score) {}
	std::string name;
	double score;
};

int main()
{
	std::vector<Person> people
	{
		{"John",181},
		{"Mary",30},
		{"Jane",179},
		{"Dylan",200},
		{"Max",198},
		{"Sasha",181},
		{"Ben",50},
		{"Ahmed",150}
	};

	for (const auto& x : people)
	{
		std::cout << x.name << "\t" << x.score << '\n';
	}

	// remove() deletes all equal values
	// remove() doesn't delete anything, it just moves all those elements at
	// the end of a vector
	// Doesn't Work with Lambda Predicate
	// std::remove() requires a direct value
	//auto result = std::remove(people.begin(), people.end(), 7);

	auto result2 = remove_if(people.begin(), people.end(), [](const Person& a)
		{
			return a.name == "Ben";
		});
	// result reterns iterator that points on the first element that we don't
	// need
	// If you want to delete something, you need to do this
	people.erase(result2, people.end());

	std::cout << '\n';
	for (const auto& x : people)
	{
		std::cout << x.name << "\t" << x.score << '\n';
	}

	people.erase(std::remove_if(people.begin(), people.end(), [](const Person& a)
		{
			return a.name == "Ahmed";
		}), people.end());

	std::cout << '\n';
	for (const auto& x : people)
	{
		std::cout << x.name << "\t" << x.score << '\n';
	}
}