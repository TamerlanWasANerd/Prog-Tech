#include <algorithm>
#include <conio.h>
#include "DoublyLinkedList.h"
#include "insertionSort.h"
#include "Price.h"
#include "reverseSentences.h"

int main()
{
	DoublyLinkedList prices;
	Price newPrice;
	std::string newItemName, newStoreName, filterItemName;
	double newPriceRub;

	bool filterEmpty = true;

	char c;
	int index, option, i = 0;

menu:
	std::cout
		<< "1. Add a price\n"
		<< "2. Remove a price\n"
		<< "3. Display price info\n"
		<< "4. Display prices with specified item name\n"
		<< "5. Edit price info\n"
		<< "6. Use copy constructor to copy last price in list\n"
		<< "7. Display sentences from a file in reverse order\n"
		<< "0. Exit\n\n";

keyscan:
	switch (c = _getch())
	{
	case '1':
		std::cout << "Enter item name: ";
		std::cin >> newItemName;
		std::cout << "Enter store name: ";
		std::cin >> newStoreName;
		std::cout << "Enter item price: ";
		std::cin >> newPriceRub;

		newPrice >> std::tuple<std::string, std::string, double>
			(newItemName, newStoreName, newPriceRub);

		prices.insertNode(0, newPrice);

		insertionSort(prices);

		break;
	case '2':
		std::cout << "Enter index of the price to be removed: ";
		std::cin >> index;
		prices.removeNode(index);

		break;
	case '3':
		if (prices.size() == 0)
			std::cout << "Nothing to display!\n";
		else
			for (i = 0; i < prices.size(); i++) 
				std::cout << prices[i];

		break;
	case '4':
		std::cout << "Enter the item name to match: ";
		std::cin >> filterItemName;

		for (i = 0; i < prices.size(); i++)
		{
			if (prices[i].getItemName() == filterItemName)
			{
				std::cout << prices[i];

				filterEmpty = false;
			}
		}

		if (filterEmpty) std::cout << "No prices match this item name!\n";

		break;
	case '5':
		std::cout << "Enter the index of the price you wish to edit: ";
		std::cin >> index;

		if (index < 0 || index >= prices.size())
		{
			std::cout << "No price with this index!\n";

			break;
		}

		std::cout << "Edit:\n"
			"1. Item name\n"
			"2. Store name\n"
			"3. Price\n";
		std::cin >> option;

		std::cout << "Enter new value: ";

		switch (option)
		{
		case 1:
			std::cin >> newItemName;
			prices[index].setItemName(newItemName);

			break;
		case 2:
			std::cin >> newStoreName;
			prices[index].setStoreName(newStoreName);

			break;
		case 3:
			std::cin >> newPriceRub;
			prices[index].setPriceRub(newPriceRub);

			break;
		default:
			std::cout << "Nothing edited, returning to menu!\n";

			break;
		}

		insertionSort(prices);

		break;
	case '6':
		if (prices.size() > 0)
			newPrice = Price(prices[prices.size() - 1]);
		else
			std::cout << "No prices to copy!\n";

		prices.insertNode(0, newPrice);

		break;
	case '7':
		try
		{
			std::cout << reverseSentences() << "\n";
		}
		catch (std::exception& e)
		{
			std::cout << e.what();
		}

		break;
	case '0':
		exit(0);
	default:
		goto keyscan;
	}

	goto menu;
}