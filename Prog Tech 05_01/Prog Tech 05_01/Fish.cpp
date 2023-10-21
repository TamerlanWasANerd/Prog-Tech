#include "Fish.h"

Fish::Fish()
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
	std::cout
		<< "Breed: " << breed << '\n'
		<< "Color: " << color << '\n'
		<< "Food: " << food << '\n';
}