#include "stdafx.h"
#include "LinkedNode.h"


LinkedNode::LinkedNode()
{
	next = NULL;
	data = 0;
}

LinkedNode::LinkedNode(int data)
{
	next = NULL;
	this->data = data;
}

LinkedNode::~LinkedNode()
{
}

/*Returns neighbor node from this one*/
LinkedNode * LinkedNode::GetNext()
{
	return next;
}

void LinkedNode::SetNext(LinkedNode * node)
{
	next = node;
}

/*Returns the content from this node*/
int LinkedNode::GetData()
{
	return data;
}

void LinkedNode::SetData(int value)
{
	data = value;
}