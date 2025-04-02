// Interface

// All methods in Interface should be pure virtual

// Abstract Classes cannot be instantiated directly

// Classes implementing an interface must override all pure virtual methods

#include <iostream>

// Abstract Class
class IBicycle
{
public:
	// A class with at least one pure virtual function is considered abstract
	// and cannot be instantiated
	void virtual turn() = 0;
	void virtual ride() = 0;
};

// SimpleBicycle implements all pure virtual methods from IBicycle, making it
// concrete
// If it did not implement them, it would still be abstract
class SimpleBicycle :public IBicycle
{
public:
	void turn() override
	{
	}
	void ride() override
	{
	}
};

class Human
{
public:
	void rideOn(IBicycle& iBicycle)
	{
		iBicycle.ride();
	}
};

int main()
{
}