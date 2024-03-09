#include "Acumulator.h"

Acumulator::Acumulator(unsigned id0, const char* brand0, const char* description0, 
	size_t capacity0, const char* batteryID0) : CarPart(id0, brand0, description0), capacity(capacity0)
{
	batteryID = new (std::nothrow) char[strlen(batteryID0) + 1];
	if(!batteryID)
	{
		CarPart::freePart();
		throw std::bad_alloc();
	}
	strcpy(batteryID, batteryID0);
}

Acumulator::Acumulator(const Acumulator& other) : CarPart(other), capacity(other.capacity)
{
	batteryID = new (std::nothrow) char[strlen(other.batteryID)];
	if(!batteryID)
	{
		CarPart::freePart();
		throw std::bad_alloc();
	}
	strcpy(batteryID, other.batteryID);
}

Acumulator& Acumulator::operator=(const Acumulator& other)
{
	if (this == &other)
		return *this;

	char* batteryIDTemp = new (std::nothrow) char[strlen(other.batteryID) + 1];
	if (!batteryIDTemp)
	{
		throw std::bad_alloc();
	}
	try
	{
		CarPart::operator=(other);
	}
	catch (const std::bad_alloc& err)
	{
		delete[] batteryIDTemp;
		throw err;
	}
	strcpy(batteryIDTemp, other.batteryID);
	delete[] batteryID;
	batteryID = batteryIDTemp;
	capacity = other.capacity;

	return *this;
}

Acumulator::~Acumulator()
{
	delete[] batteryID;
}
