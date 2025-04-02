// Multithreading - Deadlock

#include <thread>
#include <mutex>

#include <iostream>

std::mutex mtx1;
std::mutex mtx2;

void print1()
{
	// To evade a deadlock you need use mtx1 first and mtx2 next
	mtx2.lock();
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	mtx1.lock();
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			std::cout << '*';
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	mtx1.unlock();
	mtx2.unlock();
}

void print2()
{
	mtx1.lock();
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
	mtx2.lock();
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			std::cout << '#';
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		std::cout << '\n';
	}
	std::cout << '\n';
	mtx1.unlock();
	mtx2.unlock();
}

int main()
{
	std::thread t1(print1);
	std::thread t2(print2);
	t1.join();
	t2.join();
}