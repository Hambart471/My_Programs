// Operator Overloding

#include <iostream>

class Human
{
public:
	Human();
	Human& operator++();
	Human operator++(int);
	void setAge(int age);
private:
	int age;
};

Human::Human()
	: age(0) {}
// Increments age and returns *this (modified object). More efficient
Human& Human::operator++()
{
	++age;
	return *this;
}
// Creates a copy of h, increments age, and returns the original copy
// (before increment). Less efficient due to copying
Human Human::operator++(int)
{
	Human temp(*this);
	++age;
	return temp;
}
void Human::setAge(int age)
{
	this->age = age;
}

int main()
{
}