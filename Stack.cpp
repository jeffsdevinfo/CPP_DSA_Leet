#include "Stack.h"

void Stack::push(int value)
{
	Node* newNodeOnStack = new Node(value);
	newNodeOnStack->next = top;
	top = newNodeOnStack;
	height++;
}

int Stack::pop()
{
	int returnVal = INT_MIN;
	if (top != nullptr)
	{
		returnVal = top->value;
		Node* temp = top;
		top = top->next;
		delete temp;
		temp = nullptr;
		height--;
	}
	return returnVal;
}
