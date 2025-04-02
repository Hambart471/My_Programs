#include "aFunction.h"
#include "bFunction.h"

#include <iostream>

namespace myNamespace
{
	bool aFunctionWorked = false;
	void aFunction()
	{
		if (!aFunctionWorked)
		{
			std::cout << "aFunction()\n";
			aFunctionWorked = true;
			bFunction();
		}
	}
}