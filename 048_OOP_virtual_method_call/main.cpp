// Virtual Method Call

// The virtual keyword ensures that the correct getMsg() method is called based
// on the actual type of the object (BraketsMsg) rather than the type of the
// reference (Msg)

// This is a core principle of object-oriented programming, allowing derived
// classes to provide their own implementation of a method while still using
// a base class pointer or reference

#include <iostream>

class Msg
{
public:
	Msg(std::string msg) :
		msg(msg){}
	virtual std::string getMsg()
	{
		return msg;
	}
private:
	std::string msg;
};

class BraketsMsg :public Msg
{
public:
	BraketsMsg(std::string msg) :Msg(msg)
	{
	}
	// If method was not virtual we could use it without "Msg::"
	std::string getMsg() override
	{
		return "[" + Msg::getMsg() + "]";
	}
};

class Printer
{
public:
	void print(Msg& msg)
	{
		std::cout << msg.getMsg() << '\n';
	}
};

int main()
{
	Printer printer;
	BraketsMsg braketsMsg("Hello");
	printer.print(braketsMsg);
}