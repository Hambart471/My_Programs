// Lambda

#include <iostream>

class MyClass
{
public:
	void print()
	{
		std::cout << a << '\n';
	}
	void lambda()
	{
		auto f = [this]()
			{
				this->a;
				print();
			};
		f();
	}
	int a = 1;
};

int main()
{
	int a = 5;
	int b = 10;

	auto f = [&a, b]()
		{
			std::cout << a++ << '\n';
			std::cout << b << '\n';
		};

	// Const value
	auto f2 = [=]()
		{
			std::cout << a << '\n';
			std::cout << b << '\n';
		};

	// Value
	auto f3 = [=]()mutable
		{
			std::cout << a++ << '\n';
			std::cout << b << '\n';
		};

	// Reference
	auto f4 = [&]()
		{
			std::cout << a++ << '\n';
			std::cout << b << '\n';
		};

	f();

	MyClass myClass;
	myClass.lambda();

	auto f5 = []()
		{
			return 0;
		};
	auto result = f5();

	// Same thing
	auto f6 = []()->int
		{
			return 0;
		};
	auto result2 = f6();
}