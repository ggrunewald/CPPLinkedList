#pragma once

#include "LinkedNode.h"

class LinkedList
{
private:
	LinkedNode * head;

public:
	LinkedList();
	~LinkedList();

	void PushBack(int data);
	void RemoveValue(int data);
	void RemoveIndex(int index);
	void Clear();

	void Swap(int a, int b);
	void Reverse();

	int Size();
	bool IsEmpty();

	void Print();

	LinkedNode * GetTail();
	LinkedNode * GetHead();
};