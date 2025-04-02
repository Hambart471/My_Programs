// String

#include <iostream>

class MyString
{
public:
	MyString();
	MyString(const char* const str);
	MyString(const MyString& other);
	MyString(MyString&& other);
	~MyString();
	MyString& operator=(const MyString& other);
	MyString operator+(const MyString& other);
	bool operator==(const MyString& other) const;
	bool operator!=(const MyString& other) const;
	char& operator[](int index);
	int myStrlen(const char* const str);
	int getLength() const;
	void print() const;
private:
	int length;
	char* str;
};

MyString::MyString()
{
	std::cout << "Constructor\t" << this << '\n';
	length = 0;
	str = nullptr;
}
MyString::MyString(const char* const str)
{
	std::cout << "Parameterized constructor\t" << this << '\n';
	length = myStrlen(str);
	this->str = new char[length + 1];
	for (int i = 0; i < length; ++i)
	{
		*(this->str + i) = *(str + i);
	}
	*(this->str + length) = '\0';
}
MyString::MyString(const MyString& other)
{
	std::cout << "Copy constuctor\t" << this << '\n';
	length = other.length;
	str = new char[length + 1];
	for (int i = 0; i < length; ++i)
	{
		*(str + i) = *(other.str + i);
	}
	*(str + length) = '\0';
}
MyString::MyString(MyString&& other)
{
	std::cout << "Move constructor\t" << this << '\n';
	length = other.length;
	str = other.str;
	other.length = 0;
	other.str = nullptr;
}
MyString::~MyString()
{
	std::cout << "Destructor\t" << this << '\n';
	delete[] str;
}
MyString& MyString::operator=(const MyString& other)
{
	std::cout << "Copy assignment (overloaded operator=)\t" << this << '\n';

	if (this == &other)
	{
		return *this;
	}

	if (str)
	{
		delete[] str;
	}

	length = other.length;
	str = new char[length + 1];
	for (int i = 0; i < length; ++i)
	{
		*(str + i) = *(other.str + i);
	}
	*(str + length) = '\0';
	return *this;
}
MyString MyString::operator+(const MyString& other)
{
	std::cout << "Overloaded operator+\t" << this << '\n';
	MyString newString;
	newString.length = length + other.length;
	newString.str = new char[newString.length + 1];
	int i = 0;
	for (; i < length; ++i)
	{
		*(newString.str + i) = *(str + i);
	}
	for (int j = 0; j < other.length; ++i, ++j)
	{
		*(newString.str + i) = *(other.str + j);
	}
	*(newString.str + newString.length) = '\0';
	// Explicit move
	// Casts it to an rvalue, allowing the compiler to invoke the move
	// constructor instead of the copy constructor
	// However, in modern C++, RVO (Return Value Optimization) makes
	// std::move unnecessary in this case. The compiler will likely optimize
	// the return without creating extra copies, so the implicit move is
	// sufficient
	//return newString; // Implicit move (RVO)
	return std::move(newString);
}
bool MyString::operator==(const MyString& other) const
{
	if (length != other.length)
	{
		return false;
	}

	for (int i = 0; i < length; ++i)
	{
		if (*(str + i) != *(other.str + i))
		{
			return false;
		}
	}

	return true;
}
bool MyString::operator!=(const MyString& other) const
{
	return !operator==(other);
}
char& MyString::operator[](int index)
{
	return *(str + index);
}
int MyString::myStrlen(const char* const str)
{
	int i = 0;
	for (; str[i] != '\0'; ++i)
	{
	}
	return i;
}
int MyString::getLength() const
{
	return length;
}
void MyString::print() const
{
	std::cout << str << '\n';
}

void myFunction(MyString myString)
{
	std::cout << "myFunction\t\n";
}
MyString myFunction2()
{
	std::cout << "myFunction2\n";
	MyString myString;
	return myString;
}

int main()
{
	MyString myString("Hello");
	std::cout << '\n';

	MyString myString2{ "World" };
	std::cout << '\n';

	// RVO
	MyString result = myString + myString2;
	std::cout << '\n';

	result.print();
	std::cout << '\n';

	result = myString;
	result.print();
	std::cout << '\n';

	// No RVO
	result = myString + myString2;
	result.print();
	std::cout << '\n';

	MyString myString3(myString);
	myString3.print();
	std::cout << '\n';

	MyString myString4 = myString2;
	myString4.print();
	std::cout << '\n';

	result = myString + myString2;
	result.print();
	std::cout << '\n';

	myFunction(result);
	std::cout << '\n';

	myFunction2();
	std::cout << '\n';
}