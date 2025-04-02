// Static

#include <iostream>

class Apple
{
public:
	Apple();
	~Apple();
	std::string getColor() const;
	static int getCount();
	static void changeToRed(Apple& apple);
private:
	static int count;
	std::string color;
};

int Apple::count = 0;
Apple::Apple()
	: color("Green")
{
	++count;
}
Apple::~Apple()
{
	--count;
}
std::string Apple::getColor() const
{
	return color;
}
int Apple::getCount()
{
	return count;
}
void Apple::changeToRed(Apple& apple)
{
	apple.color = "Red";
}

int main()
{
	std::cout << "Initial count: " << Apple::getCount() << '\n';
    {
        Apple apple;
        std::cout << "Apple color: " << apple.getColor() << '\n';

        Apple::changeToRed(apple);
        std::cout << "Changed color: " << apple.getColor() << '\n';

        std::cout << "Count after creating apple: " << Apple::getCount() << '\n';

        Apple apple2;
        std::cout << "Count after creating apple2: " << Apple::getCount() << '\n';
    } // apple and apple2 are destroyed here automatically
    std::cout << "Count after block: " << Apple::getCount() << '\n';
}