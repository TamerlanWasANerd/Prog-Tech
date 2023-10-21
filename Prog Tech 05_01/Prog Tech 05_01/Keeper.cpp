#include "Keeper.h"
#include <fstream>
#include <string>

void Keeper::addBird()
{
	Bird newBird = Bird();

	birds.push_back(newBird);
}

void Keeper::addCat()
{
	Cat newCat = Cat();

	cats.push_back(newCat);
}

void Keeper::addFish()
{
	Fish newFish = Fish();

	fish.push_back(newFish);
}

bool Keeper::removeBird(int index)
{
	if (index < 0 || index >= birds.size())
	{
		std::cout << "No bird with such index!\n";

		return false;
	}

	birds.erase(birds.begin() + index);
	return true;
}

bool Keeper::removeCat(int index)
{
	if (index < 0 || index >= cats.size())
	{
		std::cout << "No cat with such index!\n";

		return false;
	}

	cats.erase(cats.begin() + index);
	return true;
}

bool Keeper::removeFish(int index)
{
	if (index < 0 || index >= fish.size())
	{
		std::cout << "No fish with such index!\n";

		return false;
	}

	fish.erase(fish.begin() + index);
	return true;
}

void Keeper::save()
{
	std::ofstream file("data.txt");
	std::streambuf* oldCout = std::cout.rdbuf();
	std::cout.rdbuf(file.rdbuf());

	describe();

	std::cout << "\t\t\t";
	std::cout.rdbuf(oldCout);
}

void Keeper::load()
{
	// TODO
	std::ifstream file("data.txt");
	std::string string;

	while (string != "\t\t\t")
	{
		file >> string;
	}

}


void Keeper::describe()
{
	std::cout << "Birds: \n";
	for (Bird a : birds)
	{
		a.describe();
	}

	std::cout << "Cats: \n";
	for (Cat a : cats)
	{
		a.describe();
	}

	std::cout << "Fish: \n";
	for (Fish a : fish)
	{
		a.describe();
	}
}
