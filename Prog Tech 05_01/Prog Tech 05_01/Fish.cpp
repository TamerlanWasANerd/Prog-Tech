#include "Fish.h"

void Fish::set()
{
	// TODO
	std::cout << std::endl;
	isSet = true;
}

void Fish::describe()
{
	std::cout
		<< "Breed: " << breed << '\n'
		<< "Color: " << color << '\n'
		<< "Food: " << food << "\n\n";
}