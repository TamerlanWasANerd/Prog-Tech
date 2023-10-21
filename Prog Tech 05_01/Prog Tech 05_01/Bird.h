#pragma once
#include "Animal.h"
class Bird : public Animal
{
	std::string food, geographicRange;
public:
	Bird();
	void describe();
};

