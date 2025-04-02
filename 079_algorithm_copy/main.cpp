// Algorithm Copy

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
		Person("John",181),
		Person("Mary",30),
		Person("Jane",179),
		Person("Dylan",200),
		Person("Max",198),
		Person("Sasha",181),
		Person("Ben",50),
		Person("Ahmed",150),
	};

	std::vector<Person> people2;
	copy(people.begin(), people.end(), back_inserter(people2));
	for (auto it = people2.begin(); it != people2.end(); ++it)
	{
		std::cout << it->name << '\t' << it->score << '\n';
	}

	std::vector<Person> people3;
	copy_if(people.begin(), people.end(), back_inserter(people3), [](const Person& a)
		{
			return a.score > 180;
		});
	std::cout << '\n';
	for (auto it = people3.begin(); it != people3.end(); ++it)
	{
		std::cout << it->name << '\t' << it->score << '\n';
	}
}