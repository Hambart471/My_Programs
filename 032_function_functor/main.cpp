// Functor

// Functors are objects that behave like functions
// More flexible than function pointers, work well with STL algorithms

#include <algorithm>

#include <iostream>

class MyFunctor
{
public:
	int operator()(int a, int b)
	{
		++count;
		std::cout << "MyFunctor\t" << count << "\t" << a + b << '\n';
		return a + b;
	}
private:
	int count = 0;
};

class EvenFunctor
{
public:
	void operator()(int value)
	{
		if (value % 2 == 0)
		{
			evenSum += value;
			++evenCount;
		}
	}
	void showEvenSum() const
	{
		std::cout << "Sum:\t" << evenSum << '\n';
	}
	void showEvenCount() const
	{
		std::cout << "Count:\t" << evenCount << '\n';
	}
private:
	int evenSum = 0;
	int evenCount = 0;
};

int main()
{
	MyFunctor myFunctor;
	myFunctor(1, 1);
	myFunctor(1, 2);
	myFunctor(1, 3);

	int a[]{ 1,2,55,99,44,3 };
	EvenFunctor evenFunctor;
	for (auto e : a)
	{
		evenFunctor(e);
	}

	std::for_each(std::begin(a), std::end(a), evenFunctor);

	evenFunctor.showEvenCount();
	evenFunctor.showEvenSum();
}