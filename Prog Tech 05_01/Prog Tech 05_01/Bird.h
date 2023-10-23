#pragma once
#include "Animal.h"
#include <string>
class Bird : public Animal
{
public:
	std::string food, geographicRange;

	Bird();
	Bird(std::string breed, std::string color, std::string food, std::string geographicRange);
	Bird(Bird* copyFrom);

	void createBird();
	void describe();
};