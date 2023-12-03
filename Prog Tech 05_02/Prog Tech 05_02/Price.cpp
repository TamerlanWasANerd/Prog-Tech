#include "Price.h"

Price::Price()
{
	itemName = "";
	storeName = "";
	priceRub = -1;

	std::cout << "Standard constructor called.\n";
}


Price::Price(std::string itemName, std::string storeName, double price)
{
	this->itemName = itemName;
	this->storeName = storeName;
	this->priceRub = price;

	std::cout << "Parameterized constructor called.\n";
}

Price::Price(Price* copyFrom)
{
	itemName = copyFrom->itemName;
	storeName = copyFrom->storeName;
	priceRub = copyFrom->priceRub;

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

void Price::setPriceRub(double price)
{
	this->priceRub = price;
}


std::string Price::getItemName()
{
	return itemName;
}

std::string Price::getStoreName()
{
	return storeName;
}

double Price::getPriceRub()
{
	return priceRub;
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
		<< rightHandSide.priceRub << "\n";

	return leftHandSide;
}

void operator>>(Price& leftHandSide,
	std::tuple<std::string, std::string, double> rightHandSide)
{
	leftHandSide.itemName = std::get<0>(rightHandSide);
	leftHandSide.storeName = std::get<1>(rightHandSide);
	leftHandSide.priceRub = std::get<2>(rightHandSide);
}