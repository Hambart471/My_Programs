// Two-Dimensional Dynamic Array

#include <iostream>

int main()
{
	// 1. Allocate rows
	// 2. Allocate columns
	// 3. Fill array
	// 4. Print array

	int rows;
	std::cout << "Enter the number of rows: ";
	std::cin >> rows;

	int cols;
	std::cout << "Enter the number of cols: ";
	std::cin >> cols;

	// Allocate an array of pointers (rows)
	char** tDDA = new char*[rows];

	// Allocate an array for each row (columns)
	for (int i = 0; i < rows; ++i)
	{
		*(tDDA + i) = new char[cols];
	}

	// Fill the array with random uppercase letters and print it
	for (int i = 0; i < rows; ++i)
	{
		std::cout << static_cast<const void*>(tDDA + i) << " points to ";
		std::cout << static_cast<const void*>(*(tDDA + i)) << ":\n";

		for (int j = 0; j < cols; ++j)
		{
			*(*(tDDA + i) + j) = 'A' + (rand() % 26);
			std::cout << static_cast<const void*>(tDDA[i] + j) << ":\t";
			std::cout << tDDA[i][j] << '\n';
		}
		std::cout << '\n';
	}

	// Deallocate memory
	for (int i = 0; i < rows; ++i)
	{
		delete[] tDDA[i];
	}
	delete[] tDDA;
}