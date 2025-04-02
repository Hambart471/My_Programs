// Multithreading - Recursive Mutex

#include <thread>
#include <mutex>

#include <iostream>

std::recursive_mutex rm;

void myFunction(int a)
{
	rm.lock();
	std::cout << a << " ";
	std::this_thread::sleep_for(std::chrono::milliseconds(300));
	if (a <= 1)
	{
		std::cout << '\n';
		// If an exception occurs, unlock() might never be called, leading to a
		// deadlock
		// Instead of manually locking and unlocking, use
		// std::lock_guard<std::recursive_mutex> for automatic unlocking
		rm.unlock();
		return;
	}
	--a;
	myFunction(a);
	rm.unlock();
}

int main()
{
	std::thread t1(myFunction, 10);
	std::thread t2(myFunction, 10);
	t1.join();
	t2.join();
}