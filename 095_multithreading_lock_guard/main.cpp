// Multithreading - Lock Guard

#include <thread>
#include <mutex>

#include <iostream>

std::mutex mtx;

void print(char ch)
{
	// Makes sure to unlock in the destructor
	// If you want guard to end earlier, you can create additional field of
	// view by {}
	std::lock_guard<std::mutex> lg(mtx);
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			std::cout << ch;
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}

int main()
{
	std::thread t1(print, '*');
	std::thread t2(print, '#');
	t1.join();
	t2.join();
}