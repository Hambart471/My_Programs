// Preprocessor Directives and Macros

// Preprocessor directives (#define) are used to create macros before
// compilation

// Macros substitute code before the compiler processes the file

#define DEBUG // Defines a macro named DEBUG
#define VALUE 1 // Defines a macro VALUE with the value 1
#define BEGIN { // Defines BEGIN as '{'
#define END } // Defines END as '}'
#define TAB '\t' // Defines TAB as a tab character
// Ensures correct evaluation using parentheses to prevent operator precedence
// issues
#define SUM(a, b) ((a) + (b)) // Macro function for summing two values

#include <iostream>

int main()
{
// #ifdef
#ifdef DEBUG
	std::cout << "DEBUG is defined\n";
#else
	std::cout << "DEBUG isn't defined\n";
#endif

// #ifndef
#ifndef DEBUG
	std::cout << "DEBUG isn't defined\n";
#else
	std::cout << "DEBUG is defined\n";
#endif

// #if
#if 0 < VALUE
	std::cout << "VALUE is positive\n";
#elif VALUE == 0
	std::cout << "VALUE equals 0\n";
#else
	std::cout << "VALUE is negative\n";
#endif

// other
	for (int i = 0; i < 10; ++i)
	BEGIN
		// SUM(VALUE, i) expands to ((VALUE) + (i)), ensuring correct evaluation
		std::cout << "VALUE + " << i << " =" << TAB << SUM(VALUE, i) << '\n';
	END
}
