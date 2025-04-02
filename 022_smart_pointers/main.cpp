// Smart pointers

#include <iostream>

// A custom smart pointer (SmartPointer) that automatically deletes the
// allocated memory when it goes out of scope
template<typename T>
class MyAutoPointer
{
public:
	MyAutoPointer(T* ptr)
	{
		this->ptr = ptr;
	}
	~MyAutoPointer()
	{
		delete ptr;
	}
	T& operator*()
	{
		return *ptr;
	}
private:
	T* ptr;
};

int main()
{
	// myAutoPointer points to an integer initialized to 2
	MyAutoPointer<int> myAutoPointer = new int(2);
	std::cout << *myAutoPointer << '\n';
	
	//Makes sure there is only one pointer that points to that address
	std::unique_ptr<int> up(new int(4));
	std::unique_ptr<int> up2;
	// Ownership is transferred to up2
	up2 = move(up);
	// Swaps ownership
	up2.swap(up);
	// Deletes the object and sets nullptr
	up2.reset();
	// Releases ownership (sets nullptr) without deleting the object
	up2.release();
	int* p2 = up.get();

	// Allows multiple smart pointers to share ownership of the same object
	// The object is deleted only when the last shared_ptr that owns it is
	// destroyed
	std::shared_ptr<int> sp(new int(5));
	// sp2 shares ownership with sp
	std::shared_ptr<int> sp2(sp);

	int size = 5;
	int* pa = new int[size] {1, 6, 44, 9, 8};
	// A shared_ptr that manages an array
	std::shared_ptr<int[]> sp3(pa);

	std::shared_ptr<int[]> sp4(new int[size] {1, 6, 44, 9, 8});
	for (int i = 0; i < size; ++i)
	{
		std::cout << sp4[i] << '\n';
	}
}