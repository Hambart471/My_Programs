// Multithreading - Detach

#include <thread>

#include <iostream>

void myFunction()
{
	// Delay before execution
	std::this_thread::sleep_for(std::chrono::milliseconds(250));
	for (int i = 1; i <= 14; ++i)
	{
		std::cout << i << ". Thread id: " << std::this_thread::get_id() << " myFunction()" << '\n';
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	std::cout << 15 << ". Thread id: " << std::this_thread::get_id() << " myFunction()" << '\n';
}

void myFunction2()
{
	for (int i = 6; i <= 10; ++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << i << ". Thread id: " << std::this_thread::get_id() << " myFunction2()" << '\n';
	}
}

int main()
{
	// Start a new thread executing myFunction()
	std::thread t(myFunction);
	// Detach thread from main. 't' will stop executing when main() will finish
	t.detach();

	for (int i = 1; i <= 4; ++i)
	{
		std::cout << i << ". Thread id: " << std::this_thread::get_id() << " main()" << '\n';
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		// if you are using namespace std
		//this_thread::sleep_for(0.5s);
	}
	std::cout << 5 << ". Thread id: " << std::this_thread::get_id() << " main()" << '\n';
	myFunction2();
}