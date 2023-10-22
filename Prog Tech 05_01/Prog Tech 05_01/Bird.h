#pragma once
#include "Animal.h"
class Bird : public Animal
{
public:
	std::string food, geographicRange;

	void createBird();
	void describe();
};

