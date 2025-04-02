// Multithreading - Passing Arguments to a Thread

#include <thread>

#include <iostream>

void myFunction(int a, int b)
{
	// Initial delay
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << "myFunction() started\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "a + b = " << a + b << '\n';
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	std::cout << "myFunction() finished\n";
}

int main()
{
	// Start myFunction(1, 2) in a new thread
	std::thread t(myFunction, 1, 2);
	for (int i = 1; i < 5; ++i)
	{
		std::cout << "Thread id: " << std::this_thread::get_id() << " main() " << i << '\n';
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	std::cout << "Thread id: " << std::this_thread::get_id() << " main() " << 5 << '\n';
	t.join();
}