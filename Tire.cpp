#include "Tire.h"

Tire::Tire(unsigned id0, const char* brand0, const char* description0, 
	size_t width0, size_t profile0, size_t diameter0) : CarPart(id0, brand0, description0)
{
	if (width0 < 155 || width0>365)
	{
		CarPart::freePart();
		throw "Width not valid";
	}
	if (profile0 < 30 || profile0>80)
	{
		CarPart::freePart();
		throw "Profile not valid";
	}
	if (diameter0 < 13 || diameter0>21)
	{
		CarPart::freePart();
		throw "Diameter not valid";
	}

	width = width0;
	profile = profile0;
	diameter = diameter0;
}