#pragma once
#include "Bird.h"
#include "Cat.h"
#include "Fish.h"
#include <vector>

class Keeper
{
	std::vector<Bird> birds;
	std::vector<Cat> cats;
	std::vector<Fish> fish;
public:
	void addBird();
	void addCat();
	void addFish();

	bool removeBird(int index);
	bool removeCat(int index);
	bool removeFish(int index);

	void save();
	bool load();

	bool describe();
};