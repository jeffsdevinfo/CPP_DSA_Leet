#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(int value)
{
	InitializeList(value);
}

void DoublyLinkedList::printList()
{
	std::cout << "\nPrinting Doubly Linked List: \n";
	DoublyNode* temp = head;
	while (temp != nullptr)
	{
		std::cout << " " << temp->value << ",";
		temp = temp->next;
	}
}

void DoublyLinkedList::append(int value)
{
	if (head == nullptr)
	{
		InitializeList(value);
	}
	else
	{
		DoublyNode* newNode = new DoublyNode(value);
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
		length++;
	}
}

void DoublyLinkedList::deleteLast()
{
	if (head != nullptr)
	{
		if (head == tail)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			DoublyNode* temp = tail->prev;
			delete tail;
			tail = temp;
			tail->next = nullptr;
		}
		length--;
	}
}

void DoublyLinkedList::prepend(int value)
{
	DoublyNode* newNode = new DoublyNode(value);
	if (head == nullptr)
	{
		InitializeList(value);
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
	length++;
}

void DoublyLinkedList::deleteFirst()
{
	if (head == nullptr) return;
	if (head == tail)
	{
		delete head;
		head = tail = nullptr;
	}
	else
	{
		DoublyNode* nodeToDelete = head;
		head = head->next;
		delete nodeToDelete;
		nodeToDelete = nullptr;
	}
	length--;
}

DoublyNode* DoublyLinkedList::get(int index)
{
	DoublyNode* nodeFound = nullptr;
	if (head != nullptr)
	{
		int mid = length / 2;		
		
		if (index <= mid)
		{
			DoublyNode* temp = head;
			for (int i = 0; i <= mid; i++)
			{
				if (i == index) { nodeFound = temp; break; }
				temp = temp->next;				
			}
		}
		else
		{ 
			DoublyNode* temp = tail;
			for (int i = length - 1; i > mid; i--)
			{
				if (i == index) { nodeFound = temp; break; }
				temp = temp->prev;
			}
		}
	}
	return nodeFound;
}

bool DoublyLinkedList::set(int index, int value)
{
	DoublyNode* foundNode = get(index);
	if (foundNode != nullptr)
	{
		foundNode->value = value;
		return true;
	}
	return false;
}

bool DoublyLinkedList::insert(int index, int value)
{
	bool returnVal = false;
	if (index == 0)
	{
		prepend(value);
		returnVal = true;
	}
	else if(index == length)
	{
		append(value);
		returnVal = true;
	}
	else
	{
		DoublyNode* prev = get(index - 1);
		if (prev != nullptr)
		{
			DoublyNode* newNode = new DoublyNode(value);
			DoublyNode* saveNext = prev->next;
			prev->next = newNode;
			newNode->prev = prev;
			newNode->next = saveNext;
			returnVal = true;
		}
		length++;
	}	
	return returnVal;
}

void DoublyLinkedList::deleteNode(int index)
{
	if (head != nullptr)
	{
		if (index < 0 || index >= length) { return; }
		else
		{			
			if (index == 0)
			{
				deleteFirst();
			}
			else if (index == length - 1)
			{
				deleteLast();
			}
			else
			{
				DoublyNode* temp = get(index);
				DoublyNode* prev = temp->prev;
				DoublyNode* next = temp->next;
				delete temp;
				prev->next = next;
				next = prev = prev;
				length--;
			}
		}
	}
}

void DoublyLinkedList::InitializeList(int value)
{
	DoublyNode* newNode = new DoublyNode(value);
	head = tail = newNode;
	length = 1;
}
