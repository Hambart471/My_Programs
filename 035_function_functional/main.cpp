// Functional (function wrapper)

#include <functional>
#include <vector>

#include <iostream>

void myFunction()
{
	std::cout << "myFunction()\n";
}

int sum(int a, int b)
{
	return a + b;
}

void myFunction2(int a)
{
	if (10 < a && a < 40)
	{
		std::cout << a << '\n';
	}
}

void myFunction3(int a)
{
	if (a % 2 == 0)
	{
		std::cout << a << '\n';
	}
}

void myFunction4(const std::vector<int>& v, std::function<void(int)> f)
{
	for (auto i : v)
	{
		f(i);
	}
}

void myFunction5(const std::vector<int>& v, const std::vector<std::function<void(int)>> vf)
{
	for (auto i : v)
	{
		for (auto& fi : vf)
		{
			fi(i);
		}
	}
}

int main()
{
	std::function<void()> f;
	f = myFunction;
	f();
	std::cout << '\n';

	std::function<void(int)> f2;
	f2 = [](int a)
	{
		std::cout << "Lambda " << a << '\n';
	};

	std::vector<int> v2{ 1,4,6,7,9,20,15,345,43,2 };
	myFunction4(v2, f2);
	myFunction4(v2, [](int a)
		{
			std::cout << "Lambda " << a << '\n';
		});

	std::function<int(int, int)> f3;
	f3 = sum;
	std::cout << f3(2, 2) << '\n' << '\n';

	std::vector<int> v{ 1,5,213,534,6,32 };
	myFunction4(v, myFunction2);
	std::vector<std::function<void(int)>> vf;
	vf.emplace_back(myFunction2);
	vf.emplace_back(myFunction3);
	myFunction5(v, vf);
}