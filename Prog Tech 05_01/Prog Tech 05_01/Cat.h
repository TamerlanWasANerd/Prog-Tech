#pragma once
#include "Animal.h"
class Cat : public Animal
{
	std::string name, ownerFirstName, ownerMiddleName, ownerLastName;

public:
	void set();
	void describe();
};

