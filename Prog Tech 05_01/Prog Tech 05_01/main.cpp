#include <iostream>
#include <conio.h>
#include "Keeper.h"

int main()
{
	Keeper keeper;
	char c;
	int index;

	menu:
	std::cout
		<< "1. Add bird\n"
		<< "2. Add cat\n"
		<< "3. Add fish\n"
		<< "4. Remove bird\n"
		<< "5. Remove cat\n"
		<< "6. Remove fish\n"
		<< "7. Display contents\n"
		<< "8. Save to file\n"
		<< "9. Load from file\n"
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
		std::cout << "Enter index of bird to be removed: ";
		std::cin >> index;
		keeper.removeBird(index);

		break;
	case '5':
		std::cout << "Enter index of cat to be removed: ";
		std::cin >> index;
		keeper.removeCat(index);

		break;
	case '6':
		std::cout << "Enter index of fish to be removed: ";
		std::cin >> index;
		keeper.removeFish(index);

		break;
	case '7':
		if(!keeper.describe()) std::cout << "Nothing to display!\n";

		break;
	case '8':
		keeper.save();

		std::cout << "Saved!\n";

		break;
	case '9':
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