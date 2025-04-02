// Binary File Operations (Object Serialization & Deserialization)

// Binary mode (std::ios::binary) prevents text-mode issues
// Manual serialization & deserialization avoids padding-related problems
// Encapsulation (Serialize() and Deserialize()) makes the class safer &
// portable

#include <fstream>

#include <iostream>

class Point
{
public:
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	void print() const
	{
		std::cout << "x: " << x << "\ty: " << y << '\n';
	}
	// Writes x and y as raw binary data
	void serialize(std::ofstream& out) const
    {
        out.write(reinterpret_cast<const char*>(&x), sizeof(x));
        out.write(reinterpret_cast<const char*>(&y), sizeof(y));
    }
	// Reads x and y from binary data
	void deserialize(std::ifstream& in)
    {
        in.read(reinterpret_cast<char*>(&x), sizeof(x));
        in.read(reinterpret_cast<char*>(&y), sizeof(y));
    }
private:
	int x;
	int y;
};

int main()
{
	std::string path = "fstream_object.bin";
	Point point(5, 10);
	point.print();

	std::ofstream fOut;
	// Opens fstream_object.bin in binary mode (std::ios::binary)
	fOut.open(path, std::ios::binary);

	if (!fOut)
	{
		std::cerr << "Failed to open file\n";
	}
	std::cout << "File is open\n";
	// Calls serialize(), which writes the Point object to the file
	point.serialize(fOut);
	fOut.close();

	std::ifstream fIn;
	fIn.open(path, std::ios::binary);
	if (!fIn)
	{
		std::cerr << "Failed to open file\n";
	}
	std::cout << "File is open\n";

	Point point2;
	// Calls deserialize() to load data from the file
	point2.deserialize(fIn);
	point2.print();
	fIn.close();
}