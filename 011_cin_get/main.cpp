// Pausing Execution

// std::cin.get() waits for user input (Enter key) before continuing
// It’s a cross-platform alternative to system("pause")

#include <iostream>

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		std::cout << i << '\n';
	}
	std::cout << "Press Enter to continue...";
	std::cin.get();
}