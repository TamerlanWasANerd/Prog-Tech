#include "Cat.h"

Cat::Cat()
{
	std::cout << "Enter cat's name: ";
	std::cin >> name;
	std::cout << "Enter cat's breed: ";
	std::cin >> breed;
	std::cout << "Enter cat's color: ";
	std::cin >> color;

	std::cout << "Enter cat's owner's first name: ";
	std::cin >> ownerFirstName;
	std::cout << "Enter cat's owner's middle name: ";
	std::cin >> ownerMiddleName;
	std::cout << "Enter cat's owner's last name: ";
	std::cin >> ownerLastName;
}

void Cat::describe()
{
	std::cout
		<< "Breed: " << breed << '\n'
		<< "Color: " << color << '\n'
		<< "Name: " << name << '\n'
		<< "Owner: " << ownerFirstName << " " << ownerMiddleName << " " << ownerLastName << '\n';
}