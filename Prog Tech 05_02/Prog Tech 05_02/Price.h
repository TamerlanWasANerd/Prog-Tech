#pragma once
#include <string>
#include <iostream>
#include <tuple>

class Price
{
public:
	std::string itemName, storeName;
	double price;
public:
	Price();
	Price(std::string itemName, std::string storeName, double price);
	Price(Price* copyFrom);

	~Price();

	void setItemName(std::string itemName);
	void setStoreName(std::string storeName);
	void setPrice(double price);

	std::string getItemName();
	std::string getStoreName();
	double getPrice();

	friend bool operator>(const Price& leftHandSide, const Price& rightHandSide);
	friend bool operator>=(const Price& leftHandSide, const Price& rightHandSide);
	friend bool operator<(const Price& leftHandSide, const Price& rightHandSide);
	friend bool operator<=(const Price& leftHandSide, const Price& rightHandSide);

	friend std::ostream& operator<<(std::ostream& leftHandSide, const Price& rightHandSide);
	friend void operator>>(Price& leftHandSide,
		std::tuple<std::string, std::string, double> rightHandSide);
};

bool operator>(const Price& leftHandSide, const Price& rightHandSide);
bool operator>=(const Price& leftHandSide, const Price& rightHandSide);
bool operator<(const Price& leftHandSide, const Price& rightHandSide);
bool operator<=(const Price& leftHandSide, const Price& rightHandSide);

std::ostream& operator<<(std::ostream& leftHandSide, const Price& rightHandSide);
void operator>>(Price& leftHandSide,
	std::tuple<std::string, std::string, double> rightHandSide);