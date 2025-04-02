// Algorithm Random Shuffle

#include <algorithm>
#include <random>

#include <iostream>

class IAction
{
public:
	virtual void action() const = 0;
	virtual ~IAction() = default;
};

class CatAction :public IAction
{
	virtual void action() const override
	{
		std::cout << "Pet the cat\n";
	}
};

class TeaAction :public IAction
{
	virtual void action() const override
	{
		std::cout << "Drink the tea\n";
	}
};

class DogAction :public IAction
{
	virtual void action() const override
	{
		std::cout << "Pet the dog\n";
	}
};

int main()
{
	const IAction* a[]
	{
		new CatAction(),
		new TeaAction(),
		new DogAction()
	};

	for (const IAction* const &x : a)
	{
		x->action();
	}

	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(std::begin(a), std::end(a), g);

	std::cout << '\n';
	for (const IAction* const &x : a)
	{
		x->action();
	}

	for (const IAction*& x : a)
	{
		delete x;
	}
}