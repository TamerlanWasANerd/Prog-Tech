#include "Fish.h"

Fish::Fish()
{
}

Fish::Fish(std::string breed, std::string color, std::string food)
{
	this->breed = breed;
	this->color = color;
	this->food = food;
}

Fish::Fish(Fish* copyFrom)
{
	breed = copyFrom->breed;
	color = copyFrom->color;
	food = copyFrom->food;
}

void Fish::createFish()
{
	std::cout << "Enter fish's breed: ";
	std::cin >> breed;
	std::cout << "Enter fish's color: ";
	std::cin >> color;
	std::cout << "Enter fish's food: ";
	std::cin >> food;
}

void Fish::describe()
{
	std::cout << "Fish " << breed << ' ' << color << ' ' << food << '\n';
}