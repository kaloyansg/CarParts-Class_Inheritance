#pragma once
#include "CarPart.h"
class Acumulator : public CarPart
{
	size_t capacity;
	char* batteryID;

public:
	Acumulator(unsigned, const char*, const char*, size_t, const char*);
	Acumulator(const Acumulator&);
	Acumulator& operator=(const Acumulator&);
	~Acumulator();
};