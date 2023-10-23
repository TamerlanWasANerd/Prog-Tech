#include "Keeper.h"
#include <fstream>
#include <string>
#include <sstream>

Keeper::Keeper()
{
}

Keeper::Keeper(std::vector<Bird> birds, std::vector<Cat> cats, std::vector<Fish> fish)
{
	this->birds = birds;
	this->cats = cats;
	this->fish = fish;
}

Keeper::Keeper(Keeper* copyFrom)
{
	birds = copyFrom->birds;
	cats = copyFrom->cats;
	fish = copyFrom->fish;
}

void Keeper::addBird()
{
	Bird newBird;

	newBird.createBird();

	birds.push_back(newBird);
}

void Keeper::addCat()
{
	Cat newCat;
	newCat.createCat();

	cats.push_back(newCat);
}

void Keeper::addFish()
{
	Fish newFish;
	newFish.createFish();

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

bool Keeper::load()
{
	birds.clear();
	cats.clear();
	fish.clear();

	std::ifstream file("data.txt");
	std::string line, type ;

	while (line != "\t\t\t")
	{
		std::getline(file, line);

		if (line == "\t\t\t") return true;

		std::istringstream stream(line);

		stream >> type;

		if (type == "Bird")
		{
			Bird newBird;

			stream >> newBird.breed;
			stream >> newBird.color;
			stream >> newBird.food;
			stream >> newBird.geographicRange;

			birds.push_back(newBird);
		}
		else if (type == "Cat")
		{
			Cat newCat;

			stream >> newCat.name;
			stream >> newCat.breed;
			stream >> newCat.color;
			stream >> newCat.ownerFirstName;
			stream >> newCat.ownerMiddleName;
			stream >> newCat.ownerLastName;

			cats.push_back(newCat);
		}
		else if (type == "Fish")
		{
			Fish newFish;

			stream >> newFish.breed;
			stream >> newFish.color;
			stream >> newFish.food;

			fish.push_back(newFish);
		}
		else
		{
			std::cout << "Invalid save file!\n";
			return false; 
		}
	}

	return true;
}


bool Keeper::describe()
{
	if (birds.empty() && cats.empty() && fish.empty())
	{
		return false;
	}

	for (Bird a : birds)
	{
		a.describe();
	}

	for (Cat a : cats)
	{
		a.describe();
	}

	for (Fish a : fish)
	{
		a.describe();
	}

	return true;
}
