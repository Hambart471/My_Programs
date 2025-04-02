// Fstream Operator Overloading

// Operator overloading allows custom classes to work with standard
// input/output streams

#include <fstream>

#include <iostream>

class Point
{
public:
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	int x, y;
};

// Overload output stream operator for writing to files/stdout
std::ostream& operator<<(std::ostream& os, const Point& point)
{
	os << point.x << " " << point.y;
	return os;
}

// Overload input stream operator for reading from files/stdin
std::istream& operator>>(std::istream& is, Point& point)
{
	is >> point.x >> point.y;
	return is;
}

int main()
{
	Point point(121, 245);
	std::cout << point << '\n';

	std::string path = "fstream_operator_overloading.txt";
	std::fstream f(path, std::fstream::in | std::fstream::out | std::fstream::app);
	if (!f)
	{
		std::cerr << "Failed to open file\n";
	}

	std::cout << "File is open\n";
	// Write to file
	f << point << '\n';
	// Reset file position for reading
	f.seekg(0);
	// Read objects from file
	Point point2;
	while (f >> point2)
	{
		std::cout << point2 << '\n';
	}
	f.close();
}