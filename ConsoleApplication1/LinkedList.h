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
	void PushFront(int data);
	void Insert(int data, int index);

	void RemoveValue(int data);
	void RemoveIndex(int index);
	void PopBack();
	void PopFront();
	void Clear();

	void Swap(int a, int b);
	void Reverse();

	int Size();
	bool IsEmpty();

	void Print();

	LinkedNode * Back();
	LinkedNode * Front();
};