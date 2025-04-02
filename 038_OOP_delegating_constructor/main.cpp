// Delegating Constructor

#include <iostream>

class Human
{
public:
	Human(std::string name)
		: name(name),
		age(0),
		weight(0){}
	Human(std::string name, int age)
		: Human(name)
	{
		// this->age = age; overwrites this->age = 0; from the first constructor
		this->age = age;
	}
private:
	std::string name;
	int age;
	double weight;
};

int main()
{
	Human human("Alice");
	Human human2("Bob", 25);
}