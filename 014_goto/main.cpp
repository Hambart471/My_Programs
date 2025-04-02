// Goto

// The goto statement is used to jump to a specific label within a function

// This can make the flow of control jump to the label regardless of the normal
// execution flow

#include <iostream>

int main()
{
	std::cout << "1\n";
	goto link;
	std::cout << "2\n";
	link:
	std::cout << "3\n";
}