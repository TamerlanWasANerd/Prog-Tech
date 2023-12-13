#include "DoublyLinkedList.h"
#include <iostream>

void DoublyLinkedList::insertNode(int index, Price value)
{
	if (index < 0 || index > size_)
	{
		std::cout << "No node with this index in this list!\n\n";

		return;
	}

	Node* newNode = new Node;
	newNode->value = value;

	// Вставка единственным элементом
	if (size_ == 0)
	{
		first = new Node;
		last = new Node;

		first = newNode;
		last = newNode;

		newNode->previous = nullptr;
		newNode->next = nullptr;

		++size_;
		return;
	}

	// Вставка первым элементом
	if (index == 0)
	{
		first->previous = newNode;

		first->previous->next = first;

		first = first->previous;

		++size_;

		return;
	}

	// Вставка последним элементом
	if (index == size_)
	{
		last->next = newNode;

		last->next->previous = last;

		last = last->next;

		++size_;

		return;
	}

	// Вставка с начала
	if (index <= (double)size_ / 2)
	{
		Node* currentNode = first;

		for (int i = 0; i < index; i++)
			currentNode = currentNode->next;

		// Вставка элемента
		newNode->previous = currentNode->previous;

		newNode->next = currentNode;

		currentNode->previous->next = newNode;

		currentNode->previous = newNode;

		++size_;

		return;
	}

	// Вставка с конца
	Node* currentNode = last;

	for (int i = size_ - 1; i >= index; i--)
		currentNode = currentNode->previous;

	// Вставка элемента
	newNode->next = currentNode->next;

	newNode->previous = currentNode;

	currentNode->next->previous = newNode;

	currentNode->next = newNode;

	++size_;

}

void DoublyLinkedList::removeNode(int index)
{
	if (index < 0 || index >= size_)
	{
		std::cout << "No node with this index in this list!\n\n";

		return;
	}

	if (size_ == 1)
	{
		delete(first);

		--size_;

		return;
	}

	if (index == 0)
	{
		first = first->next;

		delete(first->previous);

		--size_;

		return;
	}

	if (index == size_ - 1)
	{
		last = last->previous;

		delete(last->next);

		--size_;

		return;
	}

	// Удаление с начала
	if (index <= (double)size_ / 2)
	{
		Node* currentNode = first;

		for (int i = 0; i < index; i++)
			currentNode = currentNode->next;

		currentNode->previous->next = currentNode->next;
		currentNode->next->previous = currentNode->previous;

		delete(currentNode);

		--size_;

		return;
	}

	// Удаление с конца
	Node* currentNode = last;

	for (int i = size_ - 1; i > index; i--)
		currentNode = currentNode->previous;

	currentNode->next->previous = currentNode->previous;
	currentNode->previous->next = currentNode->next;

	delete(currentNode);

	--size_;
}

Price DoublyLinkedList::getNodeValue(int index)
{
	if (index < 0 || index >= size_)
	{
		throw std::exception("No node with this index in this list!\n\n");
	}

	// Поиск с начала
	if (index <= (double)size_ / 2)
	{
		Node* currentNode = first;

		for (int i = 0; i < index; i++)
			currentNode = currentNode->next;

		return currentNode->value;
	}

	// Поиск с конца
	Node* currentNode = last;

	for (int i = 0; i > index; i--)
		currentNode = currentNode->previous;

	return currentNode->value;
}

void DoublyLinkedList::print()
{
	Node* currentNode = first;

	for (int i = 0; i < size_ - 1; i++)
	{
		std::cout << currentNode->value << "; ";

		currentNode = currentNode->next;
	}

	std::cout << currentNode->value << "\n\n";
}

int DoublyLinkedList::size()
{
	return size_;
}


Price DoublyLinkedList::operator [](int index)
{
	return getNodeValue(index);
}