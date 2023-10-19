#include "Cat.h"

void Cat::set()
{
	std::cout << "Enter name: ";
	std::cin >> name;
	std::cout << "Enter breed: ";
	std::cin >> breed;
	std::cout << "Enter color: ";
	std::cin >> color;

	std::cout << "Enter owner's first name: ";
	std::cin >> ownerFirstName;
	std::cout << "Enter owner's middle name: ";
	std::cin >> ownerMiddleName;
	std::cout << "Enter owner's last name: ";
	std::cin >> ownerLastName;

	std::cout << std::endl;
	isSet = true;
}

void Cat::describe()
{
	std::cout
		<< "Breed: " << breed << '\n'
		<< "Color: " << color << '\n'
		<< "Name: " << name << '\n'
		<< "Owner: " << ownerFirstName << " " << ownerMiddleName << " " << ownerLastName << "\n\n";
}