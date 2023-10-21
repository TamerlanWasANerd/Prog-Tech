#pragma once
#include "Animal.h"
class Fish : public Animal
{
	std::string food;
public:
	Fish();
	void describe();
};