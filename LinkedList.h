#pragma once
#include "Node.h"
#include <iostream>
class LinkedList
{
private:
	Node* head;
	Node* tail;
	int length;

public:
	LinkedList(int value);
	~LinkedList();
	void Append(int value);
	void Prepend(int value);
	bool Insert(int index, int value);
	void PrintList();
	void DeleteLast();
	void DeleteFirst();	
	void DeleteAtIndex(int index);
	void Reverse();
	bool Set(int index, int value);
	int getLength();
	Node* findMiddleNode();
	Node* GetNodeAtIndex(int index);
	bool hasLoop(bool testOn = false);
	Node* findKthFromEnd(int k);
};

