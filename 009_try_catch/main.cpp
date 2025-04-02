// Try-Catch

#include <fstream>

#include <iostream>

int main()
{
	std::string path = "try_catch.txt";
	std::ifstream fIn;
	// Enable exceptions for failbit and badbit
	fIn.exceptions(std::ifstream::badbit | std::ifstream::failbit);

	try
	{
		fIn.open(path);
		std::cout << "File opened successfully\n";
	}
	catch (const std::ios_base::failure& e)
	{
		std::cerr << "File Exception: " << e.what() << "\n"
			<< "Error code: " << e.code() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "Unknown exception: " << e.what() << '\n';
	}
}