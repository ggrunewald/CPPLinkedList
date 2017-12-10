#pragma once
class LinkedNode
{
private:
	LinkedNode * next;
	int data;
public:
	LinkedNode();
	LinkedNode(int data);
	~LinkedNode();

	LinkedNode * GetNext();
	void SetNext(LinkedNode * node);

	int GetData();
	void SetData(int value);
};

