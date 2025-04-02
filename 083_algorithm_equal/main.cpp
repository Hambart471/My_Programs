// Algorithm Equal

#include <algorithm>
#include <vector>

#include <iostream>

class Point
{
public:
	Point(int x, int y) :
		x(x),
		y(y) {}
	int x, y;
	// Instead of using a lambda, you can overload operator==
	// inside Point
	bool operator==(const Point& other) const
	{
		return x == other.x && y == other.y;
	}
};

int main()
{
	std::vector<Point> v
	{
		{1,3},
		{4,5},
		{5,7}
	};

	std::vector<Point> v2
	{
		{1,3},
		{4,5},
		{5,7}
	};

	std::cout << std::equal(std::begin(v), std::end(v), std::begin(v2), std::end(v2), [](const Point& a, const Point& b)
		{
			return a.x == b.x && a.y == b.y;
		}) << '\n';

	std::cout << std::equal(v.begin(), v.end(), v2.begin()) << '\n';
}