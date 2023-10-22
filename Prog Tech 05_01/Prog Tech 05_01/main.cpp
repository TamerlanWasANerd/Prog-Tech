#include <iostream>
#include <conio.h>
#include "Keeper.h"

int main()
{
	Keeper keeper;
	char c;

	menu:
	std::cout
		<< "1. Add bird\n"
		<< "2. Add cat\n"
		<< "3. Add fish\n"
		<< "4. Display contents\n"
		<< "5. Save to file\n"
		<< "6. Load from file\n"
		<< "0. Exit\n\n";

	
keyscan:
	switch (c = _getch())
	{
	case '1':
		keeper.addBird();

		break;
	case '2':
		keeper.addCat();

		break;
	case '3':
		keeper.addFish();

		break;
	case '4':
		if(!keeper.describe()) std::cout << "Nothing to display!\n";

		break;
	case '5':
		keeper.save();

		std::cout << "Saved!\n";

		break;
	case '6':
		keeper.load();

		std::cout << "Loaded!\n";

		break;
	case '0':
		exit(0);
	default:
		goto keyscan;
	}

	goto menu;
}