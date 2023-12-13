#include "insertionSort.h"

// sorts a vector in ascending order using insertion sort
void insertionSort(DoublyLinkedList& list)
{
	int j, n = list.size();
	Price temp;

	for (int i = 1; i < n; ++i)
	{
		temp = list[i];
		j = i - 1;

		while (j >= 0 && list[j] > temp)
		{
			list.removeNode(j + 1);
			list.insertNode(j + 1 , list[j]);
			j = j - 1;
		}

		list.removeNode(j + 1);
		list.insertNode(j + 1, temp);
		list[j + 1] = temp;
	}
}