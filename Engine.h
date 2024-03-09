#pragma once
#include "CarPart.h"
class Engine : public CarPart
{
	size_t hoursePower;
public:
	Engine(unsigned, const char*, const char*, size_t);
};

