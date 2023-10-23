#pragma once
#include "Animal.h"
class Fish : public Animal
{
public:
	std::string food;

	Fish(std::string breed, std::string color, std::string food);

	Fish(Fish* copyFrom);

	void createFish();
	void describe();
};