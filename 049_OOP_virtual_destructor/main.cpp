// Virtual Destructor

// Always declare destructors as virtual in base classes when using polymorphism

#include <iostream>

class A
{
public:
	A()
	{
		std::cout << "A()\n";
	}
	~A()
	{
		std::cout << "~A()\n";
	}
};

class B :public A
{
public:
	B()
	{
		std::cout << "B()\n";
	}
	~B()
	{
		std::cout << "~B()\n";
	}
};

class A2
{
public:
	A2()
	{
		std::cout << "A2()\n";
	}
	virtual ~A2()
	{
		std::cout << "~A2()\n";
	}
};

class B2 :public A2
{
public:
	B2()
	{
		std::cout << "B2()\n";
	}
	~B2() override
	{
		std::cout << "~B2()\n";
	}
};

// Class C became abstract because we made pure virtual destructor
class C
{
public:
	// Any derived class must implement the destructor
	virtual ~C() = 0;
};
// A pure virtual destructor still requires a definition (C::~C() {}) in the
// base class
// The destructor always gets called, even in abstract classes
C::~C()
{
	std::cout << "~C()\n";
};

class D :public C
{
public:
	~D() override
	{
		std::cout << "~D()\n";
	}
};

int main()
{
	B b;
	std::cout << '\n';

	B* pB = new B;
	delete pB;
	std::cout << '\n';

	// Non-Virtual Destructor Causes Memory Leak
	A* pA = new B;
	delete pA; // Calls only A::~A(), NOT B::~B()
	std::cout << '\n';

	A2* pA2 = new B2;
	delete pA2; // Calls both B2::~B2() and A2::~A2()
	std::cout << '\n';
}