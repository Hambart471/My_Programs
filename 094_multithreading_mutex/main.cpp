// Multithreading - Mutex

#include <thread>
#include <mutex>

#include <iostream>

std::mutex mtx;

void print(char ch)
{
	mtx.lock();
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			std::cout << ch;
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	// If an exception occurs, unlock() might not be called, leading to a
	// deadlock
	mtx.unlock();
}

int main()
{
	std::thread t1(print, '*');
	std::thread t2(print, '#');
	t1.join();
	t2.join();
}