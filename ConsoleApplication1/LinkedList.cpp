#include "stdafx.h"

#include <iostream>

#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList()
{
	head = NULL;
}


LinkedList::~LinkedList()
{
}

void LinkedList::Insert(int data)
{
	if (head == NULL)
	{
		head = new LinkedNode(data);
	}
	else
	{
		LinkedNode * tail = GetTail();

		LinkedNode * newNode = new LinkedNode(data);

		tail->SetNext(newNode);
	}
}

void LinkedList::RemoveValue(int data)
{
	LinkedNode * currNode = head;
	LinkedNode * prevNode = NULL;

	while (currNode != NULL)
	{
		if (currNode->GetData() == data)
		{
			if (prevNode != NULL)
			{
				prevNode->SetNext(currNode->GetNext());

				if (head == currNode)
				{
					head = NULL;
				}

				currNode = prevNode->GetNext();
			}
			else
			{
				LinkedNode * nextNode = currNode->GetNext();

				delete currNode;

				head = nextNode;

				currNode = nextNode;
			}
		}
		else
		{
			prevNode = currNode;
			currNode = currNode->GetNext();
		}
	}
}

void LinkedList::RemoveIndex(int index)
{
	int i = 0;

	LinkedNode * currNode = head;
	LinkedNode * prevNode = NULL;

	while (currNode != NULL && index != i)
	{
		i++;

		prevNode = currNode;
		currNode = currNode->GetNext();
	}

	if(i != 0)
		i--;

	if (index == i)
	{
		if(prevNode != NULL)
			prevNode->SetNext(currNode->GetNext());

		if (currNode == head)
			head = NULL;

		delete currNode;
	}
}

void LinkedList::Clear()
{
	int size = Size();

	while (size > 0)
	{	
		RemoveIndex(--size);
	}

	head = NULL;
}

int LinkedList::Size()
{
	LinkedNode * currNode = head;
	
	int size = 0;

	while (currNode != NULL)
	{
		size++;
		
		currNode = currNode->GetNext();
	}

	return size;
}

bool LinkedList::IsEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

void LinkedList::Print()
{
	LinkedNode * currNode = head;

	while (currNode != NULL)
	{
		cout << currNode->GetData() << " ";

		currNode = currNode->GetNext();
	}

	if (head == NULL)
		cout << "Empty list...";

	cout << endl;
}

LinkedNode * LinkedList::GetTail()
{
	LinkedNode * currNode = head;

	while (currNode->GetNext() != NULL)
		currNode = currNode->GetNext();

	return currNode;
}

LinkedNode * LinkedList::GetHead()
{
	return head;
}
