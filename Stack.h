#pragma once
#include "Node.h"
#include <iostream>

class Stack
{
private:
	Node* top;
	int height;

public:
	Stack(int value)
	{
		top = new Node(value);
		top->next = nullptr;
		height = 1;
	}

	Stack()
	{
		top = nullptr;		
		height = 0;
	}

	void getTop() { if (top != nullptr) { std::cout << "Top: " << top->value << "\n"; } }

	void getHeight() { std::cout << "Height: " << height << "\n"; }

	void printStack()
	{
		Node* temp = top;
		while (temp != nullptr)
		{
			std::cout << temp->value << "\n";
			temp = temp->next;
		}
	}

	void push(int value);
	int pop();

};

