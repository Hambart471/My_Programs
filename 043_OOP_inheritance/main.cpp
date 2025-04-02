// Inheritance

#include <iostream>

class Human
{
public:
	Human()
	{
		std::cout << "Human()\n";
	}
	Human(int value)
	{
		std::cout << "Human(int value)\n";
	}
};

class Student :public Human
{
};

class Teacher :public Human
{
public:
	Teacher() : Human(1)
	{
	}
};

class Dean :public Human
{
public:
	Dean(int value) : Human(value)
	{
	}
};

int main()
{
	Student student;
	Teacher teacher;
	Dean dean(2);
}