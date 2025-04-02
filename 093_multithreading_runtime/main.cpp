// Multithreading - Runtime

#include <thread>

#include <iostream>

class SimpleTimer
{
public:
	SimpleTimer()
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~SimpleTimer()
	{
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		std::cout << "Total time: " << duration.count() << " seconds\n";
	}
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
};

int square(int value)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << std::this_thread::get_id() << " ============\tStart: square()\t============\n";
	value *= 2;
	std::this_thread::sleep_for(std::chrono::milliseconds(9500));
	std::cout << std::this_thread::get_id() << " ============\tEnd: square()\t============\n";
	return value;
}

int main()
{
	SimpleTimer simpleTimer;
	int value;
	std::thread t([&value]() { value = square(2);});

	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 1; i <= 9; ++i)
	{
		std::cout << std::this_thread::get_id() << "\tmain()\t" << i << '\n';
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	std::cout << std::this_thread::get_id() << "\tmain()\t" << 10 << '\n';

	t.join();
	std::cout << std::this_thread::get_id() << "\t" << value << '\n';

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float> duration = end - start;
	std::cout << "Main thread duration: " << duration.count() << " seconds\n";
}