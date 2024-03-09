#pragma once
#include <iostream>
#pragma warning (disable:4996)

class CarPart
{
	unsigned id;
	char* brand;
	char* description;

protected:
	void freePart();

public:
	CarPart(unsigned, const char*, const char*);
	CarPart(const CarPart&);
	CarPart& operator=(const CarPart&);
	~CarPart();
};

