// Multithreading - Passing Arguments to a Thread by Reference

#include <thread>

#include <iostream>

void myIncrement(int& value)
{
	// Initial delay
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << std::this_thread::get_id() << " ============\tStart: myIncrement()\t============\n";
	// Increment value by referece
	++value;
	// Simulated workload
	std::this_thread::sleep_for(std::chrono::milliseconds(5500));
	std::cout << std::this_thread::get_id() << " ============\tEnd: myIncrement()\t============\n";
}

int main()
{
	int value = 1;
	std::thread t(myIncrement, std::ref(value));

	for (int i = 1; i <= 4; ++i)
	{
		std::cout << std::this_thread::get_id() << "\tmain()\t" << i << '\n';
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	std::cout << std::this_thread::get_id() << "\tmain()\t" << 5 << '\n';
	// Ensure myIncrement() completes before accessing 'value'
	t.join();
	// Print updated value
	std::cout << std::this_thread::get_id() << "\t" << value << '\n';
}