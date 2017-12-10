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

/*Insert data at the last position of the list*/
void LinkedList::PushBack(int data)
{
	//If list still empty, inserts node as list's head
	if (head == NULL)
	{
		head = new LinkedNode(data);
	}
	else
	{
		//Looks for last element of the list
		LinkedNode * tail = GetTail();

		//Creates new node and insert it as tail's neighbor
		LinkedNode * newNode = new LinkedNode(data);

		tail->SetNext(newNode);
	}
}

/*Remove all occurences of the value data*/
void LinkedList::RemoveValue(int data)
{
	LinkedNode * currNode = head;
	LinkedNode * prevNode = NULL;

	while (currNode != NULL)
	{
		//If data found
		if (currNode->GetData() == data)
		{
			//If there is a previous node (not list's head), must update the link to new neighbor
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

/*Removes the node an position index*/
void LinkedList::RemoveIndex(int index)
{
	//If index outside of the list, exit
	if (index >= Size())
		return;

	int i = 0;

	LinkedNode * currNode = head;
	LinkedNode * prevNode = NULL;

	//Search for the chosen index
	while (currNode != NULL && index != i)
	{
		i++;

		prevNode = currNode;
		currNode = currNode->GetNext();
	}

	//If index found, removes node and delete it
	if (index == i)
	{
		if(prevNode != NULL)
			prevNode->SetNext(currNode->GetNext());

		if (currNode == head)
			head = currNode->GetNext();

		delete currNode;
	}
}

/*Removes all nodes from the list*/
void LinkedList::Clear()
{
	int size = Size();

	//While size not zero, removes first element (fastest element to remove)
	while (size > 0)
	{	
		RemoveIndex(0);

		--size;
	}

	head = NULL;
}

/*Exchanges data between node a and node b*/
void LinkedList::Swap(int a, int b)
{
	int i = 0;

	LinkedNode *ANode = NULL, *BNode = NULL, 
			   *APrev = NULL, *BPrev = NULL, 
			   *prevNode = NULL, *currNode = head;

	//Searches nodes that must be exchanged
	while (currNode != NULL)
	{
		if (i == a)
		{
			ANode = currNode;
			APrev = prevNode;
		}
		if (i == b)
		{
			BNode = currNode;
			BPrev = prevNode;
		}
		
		i++;

		prevNode = currNode;
		currNode = currNode->GetNext();
	}

	//If didnt find one of them, exits
	if (ANode == NULL || BNode == NULL)
		return;

	//Makes node swap, not simple data swap
	LinkedNode *ANext = ANode->GetNext();
	LinkedNode *BNext = BNode->GetNext();

	//Puts B on A's place
	if(APrev != NULL)
		APrev->SetNext(BNode);
	
	if(ANext != BNode)
		BNode->SetNext(ANext);
	else
		BNode->SetNext(ANode);

	//Puts A on B's place
	if (BPrev != ANode)
	{
		if (BPrev != NULL)
		{
			BPrev->SetNext(ANode);
		}
		else
		{
			BPrev->SetNext(BNode);
		}
	}
	
	ANode->SetNext(BNext);

	if (head == ANode)
		head = BNode;
	else if (head == BNode)
		head = ANode;
}

/*Reverse element's order*/
void LinkedList::Reverse()
{
	int a = 0,
		b = Size() - 1;

	while (a < b)
	{
		Swap(a, b);

		a++;
		b--;
	}
}

/*Returns list size*/
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

/*Returns true if the list is empty*/
bool LinkedList::IsEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

/*Prints in a single line all the content of the list*/
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

/*Returns last node from the list*/
LinkedNode * LinkedList::GetTail()
{
	LinkedNode * currNode = head;

	while (currNode->GetNext() != NULL)
		currNode = currNode->GetNext();

	return currNode;
}

/*Returns first node from the list*/
LinkedNode * LinkedList::GetHead()
{
	return head;
}
