#include "bFunction.h"
#include "aFunction.h"

#include <iostream>

namespace myNamespace
{
	bool bFunctionWorked = false;
	void bFunction()
	{
		if (!bFunctionWorked)
		{
			std::cout << "bFunction()\n";
			bFunctionWorked = true;
			aFunction();
		}
	}
}