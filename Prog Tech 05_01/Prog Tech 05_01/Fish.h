#pragma once
#include "Animal.h"
class Fish : public Animal
{
public:
	std::string food;

	void createFish();
	void describe();
};