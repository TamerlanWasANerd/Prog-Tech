#pragma once
#include <iostream>

class Animal
{
public:
	bool isSet = false;
	virtual void set() = 0;
	virtual void describe() = 0;

	inline virtual ~Animal()
	{
	}
protected:
	std::string breed, color;
};

