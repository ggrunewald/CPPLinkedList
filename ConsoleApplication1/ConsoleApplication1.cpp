#include "stdafx.h"

#include <iostream>

#include "LinkedList.h"
#include "ConsoleApplication1.h"

using namespace std;

int main()
{
	int x;

	cout << "Creating list with 1 element..." << endl;

	LinkedList * myList = new LinkedList();

	if (myList->IsEmpty())
		cout << "List still empty..." << endl;

	myList->Insert(1);
	
	cout << "Removing 1st element..." << endl;

	myList->RemoveIndex(0);

	if (myList->IsEmpty())
		cout << "List still empty..." << endl;

	myList->Print();

	cout << "Creating list with 7 elements..." << endl;

	myList->Insert(1);
	myList->Insert(2);
	myList->Insert(3);
	myList->Insert(3);
	myList->Insert(4);
	myList->Insert(3);
	myList->Insert(5);

	myList->Print();

	cout << "Number of elements = " << myList->Size() << endl;

	cout << "Removing value 1..." << endl;

	myList->RemoveValue(1);

	myList->Print();

	cout << "Removing 3th element..." << endl;

	myList->RemoveIndex(2);
	
	myList->Print();

	cout << "Removing 5th element..." << endl;

	myList->RemoveIndex(4);

	myList->Print();

	cout << "Number of elements = " << myList->Size() << endl;

	myList->RemoveIndex(4);

	cout << "Clearing list..." << endl;

	myList->Clear();

	myList->Print();

	cin >> x;

	return 0;
}

