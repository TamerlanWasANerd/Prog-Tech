#pragma once
#include "Animal.h"
class Cat : public Animal
{
public:
	std::string name, ownerFirstName, ownerMiddleName, ownerLastName;

	void createCat();
	void describe();
};

