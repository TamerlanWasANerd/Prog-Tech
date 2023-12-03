#include <algorithm>
#include <conio.h>
#include <vector>
#include "Price.h"
#include "reverseSentences.h"

int main()
{
	std::vector<Price> prices;
	Price newPrice;
	std::string newItemName, newStoreName, filterItemName;
	double newPriceRub;

	bool filterEmpty = true;

	char c;
	int index, option;

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

		prices.push_back(newPrice);

		std::sort(prices.begin(), prices.end());

		break;
	case '2':
		std::cout << "Enter index of the price to be removed: ";
		std::cin >> index;
		prices.erase(prices.begin() + index);

		break;
	case '3':
		if (prices.empty())
			std::cout << "Nothing to display!\n";
		else
			for (Price a : prices) std::cout << a;

		break;
	case '4':
		std::cout << "Enter the item name to match: ";
		std::cin >> filterItemName;

		for (Price a : prices)
		{
			if (a.getItemName() == filterItemName)
			{
				std::cout << a;

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
		case '1':
			std::cin >> newItemName;
			prices[index].setItemName(newItemName);

			break;
		case '2':
			std::cin >> newStoreName;
			prices[index].setStoreName(newStoreName);

			break;
		case '3':
			std::cin >> newPriceRub;
			prices[index].setPriceRub(newPriceRub);

			break;
		default:
			std::cout << "Nothing edited, returning to menu!\n";

			break;
		}

		std::sort(prices.begin(), prices.end());

		break;
	case '6':
		if (prices.size() > 0)
			newPrice = Price(prices[prices.size() - 1]);
		else
			std::cout << "No prices to copy!\n";

		prices.push_back(newPrice);

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