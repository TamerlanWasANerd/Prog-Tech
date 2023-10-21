#include "Bird.h"

Bird::Bird()
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
	std::cout
		<< "Breed: " << breed << '\n'
		<< "Color: " << color << '\n'
		<< "Food: " << food << '\n'
		<< "Range: " << geographicRange << '\n';
}