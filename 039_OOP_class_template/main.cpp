// Class Template

#include <iostream>

template<typename T>
class TypeSize
{
public:
	TypeSize(T value)
		: value(value){}
	void typeSize() const
	{
		std::cout << sizeof(value) << '\n';
	}
protected:
	T value;
};

template<typename T>
class TypeInfo :public TypeSize<T>
{
public:
	TypeInfo(T value) :TypeSize<T>(value)
	{
	}
	void showTypeName() const
	{
		std::cout << typeid(this->value).name() << '\n';
	}
};

template<typename T>
class Printer
{
public:
	void print(T value) const
	{
		std::cout << value << '\n';
	}
};

// You can restrict using method print for double like this
template<>
class Printer<double>
{
public:
	// Prevents using print() for double
	void print(double) = delete;
};

template<>
class Printer<bool>
{
public:
	void print(bool value) const
	{
		std::cout << "Bool: " << value << '\n';
	}
};

int main()
{
	TypeInfo<int> typeInfo(1);
	typeInfo.typeSize();
	typeInfo.showTypeName();
	Printer<bool> printer;
	printer.print(true);
}