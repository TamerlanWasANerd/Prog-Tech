#include "Cat.h"

Cat::Cat()
{
}

Cat::Cat(std::string name, std::string breed, std::string color, 
	std::string ownerFirstName, std::string ownerMiddleName, std::string ownerLastName)
{
	this->name = name;
	this->breed = breed;
	this->color = color;
	this->ownerFirstName = ownerFirstName;
	this->ownerMiddleName = ownerMiddleName;
	this->ownerLastName = ownerLastName;
}

Cat::Cat(Cat* copyFrom)
{
	name = copyFrom->name;
	breed = copyFrom->breed;
	color = copyFrom->color;
	ownerFirstName = copyFrom->ownerFirstName;
	ownerMiddleName = copyFrom->ownerMiddleName;
	ownerLastName = copyFrom->ownerLastName;
}

void Cat::createCat()
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
		<< "Cat " << name << ' ' << breed << ' ' << color << ' '
		<< ownerFirstName << ' ' << ownerMiddleName << ' ' << ownerLastName << '\n';
}