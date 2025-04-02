// Multithreading - Calling Member Functions in a Thread

#include <thread>

#include <iostream>

class MyClass
{
public:
	void myFunction()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << std::this_thread::get_id << "\t==========\tmyFunction()\tstart\t==========\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(5500));
		std::cout << std::this_thread::get_id << "\t==========\tmyFunction()\tfinish\t==========\n";
	}

	void myFunction2(int a)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << std::this_thread::get_id << "\t==========\tmyFunction2()\tstart\t==========\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(5500));
		std::cout << a << '\n';
		std::cout << std::this_thread::get_id << "\t==========\tmyFunction2()\tfinish\t==========\n";
	}

	int myFunction3(int a, int b)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << std::this_thread::get_id << "\t==========\tmyFunction3()\tstart\t==========\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(5500));
		std::cout << std::this_thread::get_id << "\t==========\tmyFunction3()\tfinish\t==========\n";
		return a + b;
	}
};

int main()
{
	MyClass myClass;

	// Calling via lambda
	//std::thread t(
	//	[&]()
	//	{
	//		myClass.myFunction();
	//	});

	// Calling via lambda and parameters
	//std::thread t(
	//	[&]()
	//	{
	//		myClass.myFunction2(1);
	//	});
	
	// Calling a non-parameter function
	//std::thread t(&MyClass::myFunction, &myClass);
	
	// Calling a parameterized function
	//std::thread t(&MyClass::myFunction2, &myClass, 1);

	// Capturing and returning values with lambda
	int result;
	std::thread t(
		[&]()
		{
			result = myClass.myFunction3(1, 2);
		});

	for (int i = 1; i <= 4; ++i)
	{
		std::cout << std::this_thread::get_id() << "\tmain()\t" << i << '\n';
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	std::cout << std::this_thread::get_id() << "\tmain()\t" << 5 << '\n';
	t.join();
	std::cout << result << '\n';
}