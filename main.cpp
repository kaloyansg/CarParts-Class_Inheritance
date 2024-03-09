#include <iostream>
#include "CarPart.h"
#include "Tire.h"
#include "Acumulator.h"

int main()
{
	CarPart* tire1 = nullptr;
	try
	{
		tire1 = new Tire(1, "mish", "left tire", 12, 23, 34);
	}
	catch (const char* err)
	{
		std::cerr << err << "\n";
	}
	delete tire1;

	try
	{
		Acumulator a1(2, "mish", "small", 25, "1234567890");
		Acumulator a2(3, "gishaaa", "big", 45, "9999999999");
		a1 = a2;
	}
	catch (...)
	{
		std::cerr << "Not enough memory!\n";
	}
}