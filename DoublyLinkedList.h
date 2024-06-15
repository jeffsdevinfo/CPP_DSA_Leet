#pragma once
#include "DoublyNode.h"
#include <iostream>

class DoublyLinkedList
{
private:
	DoublyNode* head;
	DoublyNode* tail;
	int length = 0;

public:
	
	DoublyLinkedList(int value);

	void printList();
	DoublyNode* getHeadNode() { return head; };
	DoublyNode* getTailNode() { return tail; };
	int getLengthValue() { return length; };

	DoublyNode* getHead() { std::cout << "Head: " << head->value << std::endl; };
	DoublyNode* getTail() { std::cout << "Tail: " << tail->value << std::endl; };
	void getLength() { std::cout << "Length: " << length<< std::endl; };

	//operations
	
	void append(int value);
	void deleteLast();
	void prepend(int value);
	void deleteFirst();
	DoublyNode* get(int index);
	bool set(int index, int value);
	bool insert(int index, int value);	
	void deleteNode(int index);

private:
	void InitializeList(int value);
};

