#pragma once
class DoublyNode
{
public:
	int value;
	DoublyNode* prev;
	DoublyNode* next;
	
	DoublyNode(int value)
	{
		this->value = value;
		prev = next = nullptr;
	}
};

