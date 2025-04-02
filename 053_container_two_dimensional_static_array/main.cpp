// Two-Dimensional Static Array

#include <iostream>

int main()
{
	// Define the dimensions
	const int ROWS = 3;
	const int COLS = 4;

	char a[ROWS][COLS];
	a[0][0] = 'A';

	// Implicitly sets ROWS = 2
	char a2[][COLS]{ {'A','B','C','D'},{'E','F','G','H'} };

	for (int i = 0; i < ROWS; ++i)
	{
		std::cout << i << ":\t";
		for (int j = 0; j < COLS; ++j)
		{
			a[i][j] = 'A' + rand() % 26;
			std::cout << "\t" << a[i][j];
		}
		std::cout << '\n';
	}
}