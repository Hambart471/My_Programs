// Algorithm Sort

#include <algorithm>
#include <vector>

#include <iostream>

class Person
{
public:
	Person(std::string name, double score) :
		name(name),
		score(score) {}
	// Define comparison operator for sorting
    bool operator<(const Person& other) const
    {
        return score < other.score;
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

	sort(v.begin(), v.end());

	for (const int& x : v)
	{
		std::cout << x << '\n';
	}

	sort(v.begin(), v.end(), [](int a, int b)
		{
			return a > b;
		});

	std::cout << '\n';
	for (const int& x : v)
	{
		std::cout << x << '\n';
	}

	const int SIZE = 3;
	int a[SIZE]{ 1,2,3 };
	std::sort(a, a + SIZE);

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

	sort(people.begin(), people.end(), [](const Person& a, const Person& b)
		{
			return a.score > b.score;
		});

	std::cout << '\n';
	for (const Person& x : people)
	{
		std::cout << x.name << "\t" << x.score << '\n';
	}

	// Sort using operator<
    std::sort(people.begin(), people.end());

	std::cout << '\n';
	for (const Person& x : people)
	{
		std::cout << x.name << "\t" << x.score << '\n';
	}
}