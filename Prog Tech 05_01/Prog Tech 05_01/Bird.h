#pragma once
#include "Animal.h"
class Bird : public Animal
{
	std::string food, geographicRange;
public:
	void set();
	void describe();
};

