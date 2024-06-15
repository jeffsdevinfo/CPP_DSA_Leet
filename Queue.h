#pragma once
#include "Node.h"
#include <iostream>
class Queue
{
private:
	Node* first;
	Node* last;
	int length;

public:
	Queue(int value)
	{
		Node* newNode = new Node(value);
		first = last = newNode;
		length = 1;
	}

	Queue()
	{
		first = last = nullptr;
		length = 0;
	}

	void enqueue(int value);
	int dequeue();	
	void printQueue();
	int getLength() { return length; }
};

