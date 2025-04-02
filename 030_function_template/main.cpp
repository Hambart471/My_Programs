// Function Template

// Function templates allow generic programming

// The compiler instantiates a specific function based on the provided types

#include <iostream>

template<typename T>
T sum(T a)
{
	return a;
}

template<typename T1, typename T2>
T1 sum2(T1 a, T2 b)
{
	return a + b;
}

int main()
{
}