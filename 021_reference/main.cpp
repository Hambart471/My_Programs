// Reference

// References behave like aliases, not like pointers
// Use pointers when you need reassignable references

#include <iostream>

int main()
{
	int a = 1;

	// A reference must be initialized at declaration and cannot be reassigned
	// A reference cannot be assigned nullptr, only pointers can
	int& aRef = a;

	std::cout << "Address of a: " << &a << '\n';
	std::cout << "Address of aRef: " << &aRef << '\n';
	std::cout << "Value of a: " << a << '\n';
	std::cout << "Value of aRef: " << aRef << '\n' << '\n';

	int* pa = &a;
	std::cout << "Address of pa: " << &pa << '\n';
	std::cout << "Value of pa: " << pa << '\n';
	std::cout << "Dereference of pa: " << *pa << '\n' << '\n';

	// Pointer to reference (same as pointer to a)
	int* paRef = &aRef;
	std::cout << "Address of paRef: " << &paRef << '\n';
	std::cout << "Value of paRef: " << paRef << '\n';
	std::cout << "Dereference of paRef: " << *paRef << '\n' << '\n';

	std::cout << pa + 1 << '\n';
	std::cout << &aRef + 1 << '\n';
	*(&aRef + 2) = 2;
	std::cout << *(&aRef + 2) << '\n';
}