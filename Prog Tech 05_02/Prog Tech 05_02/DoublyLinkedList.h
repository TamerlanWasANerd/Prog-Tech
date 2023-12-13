#pragma once
#include "Price.h"
class DoublyLinkedList
{
public:
	class Node
	{
	public:

		friend class DoublyLinkedList;

		Price value;

		Node* previous = nullptr, * next = nullptr;
	};

	Node* first, * last;

	int size_ = 0;
public:
	// Вставляет элемент в список перед элементом с указанным индексом
	void insertNode(int index, Price value);

	void removeNode(int index);

	Price getNodeValue(int index);

	void print();

	int size();

	// Возвращает элемент, находящийся по указанному индексу
	Price operator [](int index);
};