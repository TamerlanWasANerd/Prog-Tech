#include "Bird.h"

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