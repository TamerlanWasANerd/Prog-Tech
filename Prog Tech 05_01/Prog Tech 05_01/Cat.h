#pragma once
#include "Animal.h"
class Cat : public Animal
{
public:
	Cat();
	Cat(std::string name, std::string breed, std::string color, 
		std::string ownerFirstName, std::string ownerMiddleName, std::string ownerLastName);
	Cat(Cat* copyFrom);

	std::string name, ownerFirstName, ownerMiddleName, ownerLastName;

	void createCat();
	void describe();
};