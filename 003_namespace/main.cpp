// Namespace Keyword

// The namespace keyword is used to organize code into logical groups and
// prevent name conflicts between identifiers

#include <iostream>

namespace A
{
	void myFunction()
	{
		std::cout << "A\n";
	}
}

using namespace A;

namespace B
{
	void myFunction()
	{
		std::cout << "B\n";
	}
}
int main()
{
	myFunction();
	B::myFunction();
}