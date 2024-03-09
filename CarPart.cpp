#include "CarPart.h"
void CarPart::freePart()
{
	delete[] brand;
	brand = nullptr;
	delete[] description;
	description = nullptr;
}

CarPart::CarPart(unsigned id0, const char* brand0, const char* description0) : id(id0)
{
	brand = new (std::nothrow) char[strlen(brand0) + 1];
	description = new (std::nothrow) char[strlen(description0) + 1];

	if (!brand || !description)
	{
		if (brand)
			delete[] brand;
		if (description)
			delete[] description;
		throw std::bad_alloc();
	}

	strcpy(brand, brand0);
	strcpy(description, description0);
}

CarPart::CarPart(const CarPart& other) : id(other.id)
{
	brand = new (std::nothrow) char[strlen(other.brand) + 1];
	description = new (std::nothrow) char[strlen(other.description) + 1];

	if (!brand || !description)
	{
		if (brand)
			delete[] brand;
		if (description)
			delete[] description;
		throw std::bad_alloc();
	}

	strcpy(brand, other.brand);
	strcpy(description, other.description);
}

CarPart& CarPart::operator=(const CarPart& other)
{
	if (this == &other)
		return *this;

	char* brandTemp = new (std::nothrow) char[strlen(other.brand) + 1];
	char* descriptionTemp = new (std::nothrow) char[strlen(other.description) + 1];

	if (!brandTemp || !descriptionTemp)
	{
		if (brandTemp)
			delete[] brandTemp;
		if (descriptionTemp)
			delete[] descriptionTemp;
		throw std::bad_alloc();
	}

	strcpy(brandTemp, other.brand);
	strcpy(descriptionTemp, other.description);

	delete[] brand;
	delete[] description;

	brand = brandTemp;
	description = descriptionTemp;

	id = other.id;

	return *this;
}

CarPart::~CarPart()
{
	freePart();
}
