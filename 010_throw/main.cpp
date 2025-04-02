// Throw

#include <iostream>

// Custom exception class
class MyException :public std::exception
{
public:
	MyException(const char* msg, int dataState) :exception(msg)
		, dataState(dataState) {}
	int getDataState() const { return dataState; }
	const char* what() const override
	{
		return "MyException"; // Custom error message
	}
private:
	int dataState;
};

// Function that throws exceptions
void myFunction(int value)
{
	if (value < 1)
	{
		throw std::runtime_error("Value is lower than 1");
	}
	else if (value == 1)
	{
		throw MyException("Number equals 1", value);
	}
	std::cout << value << '\n';
}

int main()
{
	try
	{
		myFunction(1); // Calling with value 1 triggers MyException
	}
	catch (const std::runtime_error& e)
	{
		std::cout << "Runtime_error: " << e.what() << '\n';
	}
	catch (const MyException& e)
	{
		std::cout << "MyException: " << e.what() << '\n';
		std::cout << "Data state: " << e.getDataState() << '\n';
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}
	catch (...)
	{
		std::cout << "Caught an unknown exception\n";
	}
}