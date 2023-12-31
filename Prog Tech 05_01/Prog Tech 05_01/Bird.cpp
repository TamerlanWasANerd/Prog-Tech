#include "Bird.h"

Bird::Bird()
{
}

Bird::Bird(std::string breed, std::string color, std::string food, std::string geographicRange)
{
	this->breed = breed;
	this->color = color;
	this->food = food;
	this->geographicRange = geographicRange;
}

Bird::Bird(Bird* copyFrom)
{
	breed = copyFrom->breed;
	color = copyFrom->color;
	food = copyFrom->food;
	geographicRange = copyFrom->geographicRange;
}

void Bird::operator=(Bird const& rightHand)
{
	breed = rightHand.breed;
	color = rightHand.color;
	food = rightHand.food;
	geographicRange = rightHand.geographicRange;
}

void Bird::createBird()
{
	std::cout << "Enter bird's breed: ";
	std::cin >> breed;
	std::cout << "Enter bird's color: ";
	std::cin >> color;
	std::cout << "Enter bird's food: ";
	std::cin >> food;
	std::cout << "Enter bird's range: ";
	std::cin >> geographicRange;
}

void Bird::describe()
{
	std::cout << "Bird " << breed << ' ' << color << ' ' << food << ' ' << geographicRange << '\n';
}

std::ostream& operator<<(std::ostream& leftHandSide, const Bird& rightHandSide)
{
	leftHandSide << "Bird " << rightHandSide.breed << ' ' << rightHandSide.color << ' ' 
		<< rightHandSide.food << ' ' << rightHandSide.geographicRange << '\n';

	return leftHandSide;
}
