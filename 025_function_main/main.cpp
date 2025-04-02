// Main Function

// argc: This is the count of arguments passed to the program (including the
// name of the program itself)

// argv: This is an array of char* where each element is a string (C-string)
// corresponding to one of the arguments passed to the program

// For example, if you run the program with:
// ./myprogram arg1 arg2 arg3
// argc will be 4 (because there are 4 arguments: the program name itself, arg1,
// arg2, and arg3)
// argv[0] will be "./myprogram", argv[1] will be "arg1", and so on

#include <iostream>

int main(int argc, char* argv[])
{
	// Loop through all the arguments passed to the program
	for (int i = 0; i < argc; ++i)
	{
		// Print each argument
		std::cout << argv[i] << '\n';
	}
}