#pragma once

#include "LinkedNode.h"

class LinkedList
{
private:
	LinkedNode * head;

public:
	LinkedList();
	~LinkedList();

	void Insert(int data);
	void RemoveValue(int data);
	void RemoveIndex(int index);
	void Clear();

	int Size();
	bool IsEmpty();

	void Print();

	LinkedNode * GetTail();
	LinkedNode * GetHead();
};