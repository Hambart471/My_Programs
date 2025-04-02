// Dynamic Array

#include <iostream>

// Fill array with random uppercase letters
void fillArray(char* const dA, const int& SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		*(dA + i) = 'A' + rand() % 26;
		// same as
		//dA[i] = 'A' + rand() % 26;
	}
}

// Print array elements with addresses
void printArray(const char* const dA, const int& SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		// by default std::cout treats char* as a string
		std::cout << "Address: " << static_cast<const void*>(dA + i) << '\n';
		std::cout << "Data: " << *(dA + i) << '\n';
		// same as
		//std::cout << "Data: " << dA[i] << '\n';
		std::cout << '\n';
	}
}

// Copy one dynamic array to another
void copyArray(const char* const dA, char*& dA2, const int& SIZE, int& size2)
{
	size2 = SIZE;
	if (dA2)
		delete[] dA2;
	dA2 = new char[size2];

	for (int i = 0; i < size2; ++i)
	{
		*(dA2 + i) = *(dA + i);
		// same as
		//dA2[i] = dA[i];
	}
}

// Add an element to the end of the dynamic array
void pushBack(char*& dA, int& size, const char& value)
{
	char* newDA = new char[size + 1];
	for (int i = 0; i < size; ++i)
	{
		newDA[i] = dA[i];
	}
	newDA[size] = value;
	++size;
	delete[] dA;
	dA = newDA;
}

// Remove last element from the dynamic array
void popBack(char*& dA, int& size)
{
	if (!size)
		return;

	--size;
	char* newDA = new char[size];
	for (int i = 0; i < size; ++i)
	{
		newDA[i] = dA[i];
	}
	delete[] dA;
	dA = newDA;
}

int main()
{
	int size;
	std::cout << "Enter size: ";
	std::cin >> size;
	std::cout << '\n';

	// Allocate dynamic array
	char* dA = new char[size];

	// Print empty array
	std::cout << "dA: ============\n";
	for (int i = 0; i < size; ++i)
	{
		// by default std::cout treats char* as a string
		std::cout << "Address: " << static_cast<const void*>(dA + i) << '\n';
		std::cout << "Data: " << *(dA + i) << '\n';
		// same as
		//std::cout << "Data: " << dA[i] << '\n';
		std::cout << '\n';
	}

	int size2;
	std::cout << "Enter size: ";
	std::cin >> size2;
	std::cout << '\n';

	// Allocate second dynamic array and fill it
	char* dA2 = new char[size2];
	fillArray(dA2, size2);

	std::cout << "dA2: ============\n";
	printArray(dA2, size2);

	// Copy dA2 into dA
	copyArray(dA2, dA, size2, size);
	std::cout << "dA: ============\n";
	printArray(dA, size);

	// Add a new element
	char value;
	std::cout << "Enter a value: ";
	std::cin >> value;
	std::cout << '\n';

	pushBack(dA, size, value);
	std::cout << "dA: ============\n";
	printArray(dA, size);

	// Remove last element from dA2
	popBack(dA2, size2);
	std::cout << "dA2: ============\n";
	printArray(dA2, size2);

	// Free memory
	delete[] dA;
	delete[] dA2;
}