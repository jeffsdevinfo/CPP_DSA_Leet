#include "Queue.h"

void Queue::enqueue(int value)
{
	Node* newNode = new Node(value);
	if (first == nullptr)
	{
		first = last = newNode;
	}
	else
	{ 
		last->next = newNode;
		last = newNode;
	}
	length++;
}

int Queue::dequeue()
{
	int returnVal = INT_MIN;
	if (first != nullptr)
	{
		returnVal = first->value;
		Node* temp = first;		
		first = first->next;		
		if (last == temp) { last = first; }
		delete temp;
		temp = nullptr;		
		length--;
	}
	
	return returnVal;
}

void Queue::printQueue()
{
	Node* temp = first;
	while (temp != nullptr)
	{
		std::cout << "\n" << temp->value;
		temp = temp->next;
	}
}
