// Nested Class

#include <string>

#include <iostream>

class Image
{
public:
	class Pixel
	{
	public:
		Pixel(int r, int g, int b);
		std::string getInfo() const;
	private:
		int r;
		int g;
		int b;
	};
	void getImageInfo() const;
private:
	static const int LENGTH = 5;
	Pixel pixels[LENGTH]
	{
		Pixel(0,1,2),
		Pixel(3,4,5),
		Pixel(6,7,8),
		Pixel(9,10,11),
		Pixel(12,13,14)
	};
};

Image::Pixel::Pixel(int r, int g, int b) :
	r(r),
	g(g),
	b(b){}
std::string Image::Pixel::getInfo() const
{
	return "Pixel: r = " + std::to_string(r) + ", g = " + std::to_string(g) + ", b = " + std::to_string(b);
}

void Image::getImageInfo() const
{
	for (int i = 0; i < LENGTH; ++i)
	{
		std::cout << pixels[i].getInfo() << '\n';
	}
}

class Image2
{
public:
	class Pixel
	{
	public:
		Pixel(int r, int g, int b);
		std::string getInfo() const;
	private:
		int r;
		int g;
		int b;
	};
	void getImageInfo() const;
private:
	static const int LENGTH = 5;
	Pixel pixels[LENGTH]
	{
		Pixel(0,1,2),
		Pixel(3,4,5),
		Pixel(6,7,8),
		Pixel(9,10,11),
		Pixel(12,13,14)
	};
};

Image2::Pixel::Pixel(int r, int g, int b) :
	r(r),
	g(g),
	b(b){}
std::string Image2::Pixel::getInfo() const
{
	return "Pixel: r = " + std::to_string(r) + ", g = " + std::to_string(g) + ", b = " + std::to_string(b);
}

void Image2::getImageInfo() const
{
	for (int i = 0; i < LENGTH; ++i)
	{
		std::cout << pixels[i].getInfo() << '\n';
	}
}

int main()
{
	Image image;
	image.getImageInfo();

	std::cout << '\n';
	Image::Pixel pixel(0, 1, 2);
	std::cout << pixel.getInfo() << '\n';

	std::cout << '\n';
	Image2 image2;
	image2.getImageInfo();

	// The class Pixel has the same name in both Image and Image2,
	// but they belong to different scopes
	// Their implementations can differ independently

	std::cout << '\n';
	Image2::Pixel pixel2(0, 1, 2);
	std::cout << pixel2.getInfo() << '\n';
}