// Multithreading - Unique Lock

#include <thread>
#include <mutex>

#include <iostream>

std::mutex mtx;

void print(char ch)
{
	// std::unique_lock should be constructed with locking enabled, unless
	// delayed with std::defer_lock
	std::unique_lock<std::mutex> ul(mtx, std::defer_lock);
	// Same as lock_guard but with unlock
	// Also we can decide to put it at other place but call the lock method
	//std::unique_lock<std::mutex> ul(mtx); // Automatically locks mutex
	ul.lock();
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
	// If you want you can not use ul.unlock
	ul.unlock();
}

int main()
{
	std::thread t1(print, '*');
	std::thread t2(print, '#');
	t1.join();
	t2.join();
}