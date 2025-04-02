// Multi-File Project

#include "MyClass.h"
#include "sum.h"
#include "aFunction.h"
#include "bFunction.h"

#include <iostream>

int main()
{
	myNamespace::MyClass myClass;
	myClass.printMessage("Hello, World!");

	std::cout << myNamespace::sum(1, 2) << '\n';

	myNamespace::aFunction();

	myNamespace::bFunction();
}