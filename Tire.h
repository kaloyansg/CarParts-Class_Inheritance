#pragma once
#include "CarPart.h"
class Tire : public CarPart
{
	size_t width;
	size_t profile;
	size_t diameter;

public:
	Tire(unsigned, const char*, const char*, size_t, size_t, size_t);
};

