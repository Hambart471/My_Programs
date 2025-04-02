#include "MyClass.h"

#include <iostream>

namespace myNamespace
{
	void MyClass::printMessage(const char* msg)
	{
		std::cout << msg << '\n';
	}
}