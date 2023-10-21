#pragma once
#include "Animal.h"
class Cat : public Animal
{
	std::string name, ownerFirstName, ownerMiddleName, ownerLastName;

public:
	Cat();
	void describe();
};

