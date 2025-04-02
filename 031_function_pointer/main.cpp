// Function Pointer

// Function pointers store addresses of functions
// They allow dynamic function calls (useful for callbacks, event handling,
// etc.)

// You can pass function pointers as parameters to other functions

#include <iostream>

void myFunction()
{
	std::cout << "myFunction()\n";
}

std::string myFunction2()
{
	return "myFunction2()";
}

// Function pointer as parameter
void showInfo(std::string (*myFunction2)())
{
	std::cout << myFunction2() << '\n';
}

int main()
{
	// Function pointer declaration
	void (*pf)() = myFunction;
	// Function call through pointer
	pf();

	// Passing function pointer
	showInfo(myFunction2);
}