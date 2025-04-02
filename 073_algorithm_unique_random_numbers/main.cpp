// Unique Random Numbers

#include <random>

#include <iostream>

int main()
{
	std::random_device rd;
	std::mt19937 g(rd());

	const int SIZE = 10;
	int randomNumbers[SIZE];

	for (int i = 0; i < SIZE;)
	{
		int randomNumber = g() % SIZE;
		bool unique = true;

		for (int j = 0; j < i; ++j)
		{
			if (randomNumber == randomNumbers[j])
			{
				unique = false;
				break;
			}
		}

		if (unique)
		{
			randomNumbers[i] = randomNumber;
			++i;
		}
	}

	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << i << " = " << randomNumbers[i] << '\n';
	}
}