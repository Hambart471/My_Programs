// Universal File Stream

#include <fstream>
#include <string>

#include <iostream>

int main()
{
	std::string path = "fstream_universal.txt";
	// If the file doesn’t exist, std::ios::in prevents its creation
	std::fstream f(path, std::ios::in | std::ios::out | std::ios::app);
	if (!f)
	{
		std::cerr << "Failed to open file\n";
	}

	std::cout << "File is open\n";
	std::cout << "Enter 1 to input value or 2 to read value: ";
	int choise;
	std::cin >> choise;
	std::cin.ignore(); // Prevent leftover newline issues
	if (choise == 1)
	{
		std::string msg;
		std::cout << "Enter text: ";
		std::getline(std::cin, msg);
		f << msg << '\n';
	}
	else if (choise == 2)
	{
		f.seekg(0); // Move read position to the beginning
		std::string msg;
		while (std::getline(f, msg))
		{
			std::cout << msg << '\n';
		}
	}
	f.close();
}