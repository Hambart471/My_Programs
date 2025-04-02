// Predicate

// Works well with standard algorithms

#include <vector>
#include <algorithm>

#include <iostream>

// Shows how functors can be used as predicates
class Person
{
public:
	explicit Person(std::string name, double score)
		: name(std::move(name)),
		score(score){}

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
	std::vector<int> v{ 1,-2,-55,9,-3,8,2 };
	std::cout << greaterThanZero(1) << '\n';
	int result = count_if(v.begin(), v.end(), greaterThanZero);
	std::cout << result << '\n';
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
	int result2 = count_if(people.begin(), people.end(), people.front());
	std::cout << result2 << '\n';
}