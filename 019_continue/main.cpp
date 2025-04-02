// Continue Statement

// Used inside loops to skip the current iteration and proceed to the next one

#include <iostream>

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		if (i == 5)
		{
			continue;
		}
		std::cout << i << '\n';
	}
}