// Multithreading - Lambda with Capture and Return Value

#include <thread>

#include <iostream>

int myIncrement(int value)
{
	// Initial delay
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	std::cout << std::this_thread::get_id() << " ============\tStart: myIncrement()\t============\n";
	// Increment value
	++value;
	// Simulated workload
	std::this_thread::sleep_for(std::chrono::milliseconds(5500));
	std::cout << std::this_thread::get_id() << " ============\tEnd: myIncrement()\t============\n";
	return value;
}

int main()
{
	int value = 0;
	// Lambda captures 'value' by reference
	std::thread t(
		[&value]()
		{
			value = myIncrement(value);
		});
	for (int i = 1; i <= 4; ++i)
	{
		std::cout << std::this_thread::get_id() << "\tmain()\t" << i << '\n';
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	std::cout << std::this_thread::get_id() << "\tmain()\t" << 5 << '\n';
	// Wait for the thread to finish
	t.join();
	// Print updated value
	std::cout << std::this_thread::get_id() << "\t" << value << '\n';
}