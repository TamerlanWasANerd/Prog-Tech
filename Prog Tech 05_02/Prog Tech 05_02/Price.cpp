#include "Price.h"

Price::Price()
{
	itemName = "";
	storeName = "";
	price = -1;

	std::cout << "Standard constructor called.\n";
}


Price::Price(std::string itemName, std::string storeName, double price)
{
	this->itemName = itemName;
	this->storeName = storeName;
	this->price = price;

	std::cout << "Parameterized constructor called.\n";
}

Price::Price(Price* copyFrom)
{
	itemName = copyFrom->itemName;
	storeName = copyFrom->storeName;
	price = copyFrom->price;

	std::cout << "Copy constructor called.\n";
}

Price::~Price()
{
	std::cout << "Destructor called.\n";
}

void Price::setItemName(std::string itemName)
{
	this->itemName = itemName;
}

void Price::setStoreName(std::string storeName)
{
	this->storeName = storeName;
}

void Price::setPrice(double price)
{
	this->price = price;
}


std::string Price::getItemName()
{
	return itemName;
}

std::string Price::getStoreName()
{
	return storeName;
}

double Price::getPrice()
{
	return price;
}


bool operator>(const Price& leftHandSide, const Price& rightHandSide)
{
	return (leftHandSide.itemName.compare(rightHandSide.itemName)) > 0;
}

bool operator>=(const Price& leftHandSide, const Price& rightHandSide)
{
	return !(leftHandSide < rightHandSide);
}

bool operator<(const Price& leftHandSide, const Price& rightHandSide)
{
	return (leftHandSide.itemName.compare(rightHandSide.itemName)) < 0;
}

bool operator<=(const Price& leftHandSide, const Price& rightHandSide)
{
	return !(leftHandSide > rightHandSide);
}

std::ostream& operator<<(std::ostream& leftHandSide, const Price& rightHandSide)
{
	leftHandSide
		<< rightHandSide.itemName << " "
		<< rightHandSide.storeName << " "
		<< rightHandSide.price << "\n";

	return leftHandSide;
}

void operator>>(Price& leftHandSide,
	std::tuple<std::string, std::string, unsigned short, unsigned short> rightHandSide)
{
	leftHandSide.itemName = std::get<0>(rightHandSide);
	leftHandSide.storeName = std::get<1>(rightHandSide);
	leftHandSide.price = std::get<2>(rightHandSide);
}