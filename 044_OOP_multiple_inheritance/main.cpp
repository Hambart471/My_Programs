// Multiple Inheritance

#include <iostream>

class Car
{
public:
	void drive()
	{
	}
};

class Plane
{
public:
	void drive()
	{
	}
	void fly()
	{
	}
};

class FlyingCar :public Car, public Plane
{
};

int main()
{
	FlyingCar flyingCar;
	flyingCar.Car::drive();
	flyingCar.fly();
}