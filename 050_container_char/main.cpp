// Char

#include <iostream>

void myFunction(const char* const str)
{
	std::cout << strlen(str) << '\n';
	std::cout << str << '\n';
}

int main()
{
	// Character Arrays
	// Implicitly null-terminated
	char myString[]{ "Hello, World!" };
	// Manually null-terminated
	char myString2[]{ 'A','\0'};
	// String Literals
	const char* myString3{ "Hello, World!" };
	// Array of String Literals
	const char* a[]{ "Hello", "World" };
	// Char Array with Fixed Size
	// A string array with space for 255 chars
	char a2[255]{ "Hello" };
	char a3[255]{ "World" };
	strcat_s(a2, a3);
	myFunction(a2);
}