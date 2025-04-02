// Friend

#include <iostream>

class Apple;

class Human
{
public:
	void takeApple(const Apple& apple) const;
private:
	friend void initialization(Apple& apple, Human& human);
	friend Apple;
};

class Apple
{
public:
	Apple(int weight, std::string color);
private:
	int weight;
	std::string color;
	friend void Human::takeApple(const Apple& apple) const;
	friend void initialization(Apple& apple, Human& human);
};

void Human::takeApple(const Apple& apple) const
{
	std::cout << "takeApple()\n"
		<< "Weight: " << apple.weight << '\n'
		<< "Color: " << apple.color << '\n';
}

Apple::Apple(int weight, std::string color)
	: weight(weight),
	color(color){}

void initialization(Apple& apple, Human& human)
{
	std::cout << "Weight: " << apple.weight << "\t" << "Color: " << apple.color << '\n';
	apple.weight = 0;
	apple.color = "No color";
	std::cout << "Weight: " << apple.weight << "\t" << "Color: " << apple.color << '\n';
}

int main()
{
	Human human;
	Apple apple(100, "Red");
	human.takeApple(apple);

	std::cout << '\n';
	initialization(apple, human);

	std::cout << '\n';
	human.takeApple(apple);
}