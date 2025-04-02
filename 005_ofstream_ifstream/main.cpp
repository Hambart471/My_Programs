// File Stream Operations

#include <fstream>
#include <string>

#include <iostream>

int main()
{
	std::string path = "fstream.txt";
	std::ofstream fOut;
	fOut.open(path);

	// To append data instead of replacing it
	// fOut.open(path, std::ofstream::app);

	// Directly initialize the ofstream
	// std::ofstream fOut(path, std::ofstream::app);

	// Prevents operations on an unopened file
	if (!fOut.is_open()) // or just (!fOut)
	{
		std::cerr << "Failed to open the file\n";
	}

	std::cout << "Enter data: ";
	std::string s;
	// Reads an entire line, including spaces
	getline(std::cin, s);
	//std::cin >> s;
	// Writes input to the file
	fOut << s << '\n';
	// Closes the file to ensure data is saved
	fOut.close();

	std::ifstream fIn(path);
	if (!fIn)
	{
		std::cerr << "Failed to open the file\n";
	}

	// Reads words separated by spaces
	//while (fIn >> s)
	//{
	//	std::cout << s << '\n';
	//}

	// Reads every character, including spaces
	//char c;
	//while (fIn.get(c))
	//{
	//	std::cout << c;
	//}

	// Reads the file line by line, preserving spaces
	while (getline(fIn, s))
	{
		std::cout << s << '\n';
	}
	// Releases the file resource after reading
	fIn.close();
}