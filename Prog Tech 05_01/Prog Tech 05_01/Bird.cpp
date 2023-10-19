#include "Bird.h"

void Bird::set()
{
	// TODO
	std::cout << std::endl;
	isSet = true;
}

void Bird::describe()
{
	std::cout
		<< "Breed: " << breed << '\n'
		<< "Color: " << color << '\n'
		<< "Food: " << food << '\n'
		<< "Range: " << geographicRange << "\n\n";
}