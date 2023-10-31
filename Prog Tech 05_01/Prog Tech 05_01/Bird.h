#pragma once
#include "Animal.h"
#include <string>
#include <ostream>
class Bird : public Animal
{
public:
	std::string food, geographicRange;

	Bird();
	Bird(std::string breed, std::string color, std::string food, std::string geographicRange);
	Bird(Bird* copyFrom);

	void operator=(Bird const& rightHandSide);
	friend std::ostream& operator<<(std::ostream& leftHandSide, const Bird& rightHandSide);

	void createBird();
	void describe();
};

std::ostream& operator<<(std::ostream& leftHandSide, const Bird& rightHandSide);