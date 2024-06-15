#include "LinkedList.h"

LinkedList::LinkedList(int value)
{
	Node* newNode = new Node(value);
	head = newNode;
	tail = head;
	length = 1;	
}

LinkedList::~LinkedList()
{
	std::cout << "\n\LinkedList Destructor";
	Node* temp = head;
	while (temp != nullptr)
	{
		Node* next = temp->next;
		std::cout << "\n\tDestroying :" << temp->value;
		delete(temp);
		temp = next;
		head = temp;
		length--;
	}
	std::cout << "\n";
}

void LinkedList::Append(int value)
{
	Node* newNode = new Node(value);
	if (length == 0)
	{
		head = newNode;
		tail = head;		
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	length++;
}

void LinkedList::Prepend(int value)
{
	Node* newNode = new Node(value);
	if (length == 0)
	{		
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	length++;
}

bool LinkedList::Insert(int index, int value)
{
	bool success = false;
	if (index >= 0 || index <= length)
	{		
		if (index == 0)
		{
			Prepend(value);
		}
		else if (index == length)
		{
			Append(value);
		}
		else
		{
			Node* nodeToInsert = new Node(value);
			Node* temp = head;		
			Node* prev = head;
			//find the position to insert at
			for (int i = 0; i < length; i++)
			{
				if (index == i)
				{
					break;
				}
				prev = temp;
				temp = temp->next;
			}
			nodeToInsert->next = prev->next;
			prev->next = nodeToInsert;
			length++;
		}
		success = true;		
	}
	return success;
}

void LinkedList::PrintList()
{
	std::cout << "\n\nPrinting out list - nunmber of items = " << length << "\n";
	Node* temp = head;
	while (temp != nullptr)
	{
		std::cout << "\t" << temp->value << std::endl;
		temp = temp->next;
	}
}

void LinkedList::DeleteLast()
{
	if (length == 0) return;
	if (length >= 2)
	{
		Node* temp = head;
		while (temp->next != tail)
		{
			temp = temp->next;
		}
		delete(temp->next);
		temp->next = nullptr;
		tail = temp;
	}
	else if(length == 1)
	{
		delete(head);
		head = tail = nullptr;
	}
	length--;	
}

void LinkedList::DeleteFirst()
{
	Node* temp = head;
	if (length == 0) return;	
	else if (length == 1)
	{
		head = tail = nullptr;
	}
	else
	{
		head = head->next;
	}
	delete(temp);
	length--;
}

void LinkedList::DeleteAtIndex(int index)
{
	if (index >= 0 && index < length)
	{
		if (index == 0)
		{
			DeleteFirst();
		}
		else if (index == length - 1)
		{
			DeleteLast();
		}
		else
		{
			Node* temp = head;
			Node* prev = head;
			for (int i = 0; i < index; i++)
			{
				prev = temp;
				temp = temp->next;
			}
			prev->next = temp->next;
			delete(temp);
			temp = nullptr;
			length--;
		}		
	}
}

void LinkedList::Reverse()
{
	if (length <= 1) { return; }
	Node* preservedTail = tail;
	Node* preservedHead = head;
	Node* current = head->next;
	head->next = nullptr; //new tail next
	tail->next = head;
	
	for (int i = 2; i < length; i++)
	{
		Node* preserveCurrentNext = current->next;
		Node* preserveNewFrontNext = tail->next;
		
		current->next = preserveNewFrontNext;
		tail->next = current;
		current = preserveCurrentNext;
	}	

	head = preservedTail;
	tail = preservedHead;
}

bool LinkedList::Set(int index, int value)
{
	bool returnVal = false;
	Node* foundNode = GetNodeAtIndex(index);
	if (foundNode)
	{
		returnVal = true;
		foundNode->value = value;
	}
	return returnVal;
}

int LinkedList::getLength()
{
	return length;
}

Node* LinkedList::findMiddleNode()
{
	Node* returnNode = nullptr;
	if(head != nullptr)
	{
		Node* slow = head;
		Node* fast = head;
		int loopCount = 0;
		while (fast != tail)
		{
			loopCount = 0;
			slow = slow->next;
			while (loopCount < 2)
			{
				if (fast->next != nullptr)
				{
					fast = fast->next;
				}
				loopCount++;
			}
		}
		if (fast == slow)
		{
			returnNode = head;
		}
		else
		{
			returnNode = slow;
		}
	}

	return returnNode;
}

Node* LinkedList::GetNodeAtIndex(int index)
{	
	Node* temp = nullptr;
	if (length > 0 && index >= 0 && index < length)
	{
		temp = head;
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}		
	}
	return temp;
}

bool LinkedList::hasLoop(bool testOn)
{
	bool returnVal = false;
	if (head != nullptr)
	{
		if (testOn)
		{
			tail->next = head;
		}
		Node* slow = head;
		Node* fast = head;
		if (slow->next == fast)
		{
			returnVal = true;
		}
		else if (head->next != nullptr)
		{
			bool foundLoop = false;
			while (fast->next != nullptr && !returnVal)
			{				
				int loopCount = 0;
				while (loopCount < 2)
				{
					if (fast->next != nullptr)
					{
						fast = fast->next;
						if(fast == slow)
						{
							returnVal = true;
							break;
						}
					}
					loopCount++;
				}				
				slow = slow->next;
			}
		}
		if (testOn)
		{
			tail->next = nullptr;
		}
	}
	return returnVal;
}

Node* LinkedList::findKthFromEnd(int k)
{	
	Node* returnNode = nullptr;	
	if (head != nullptr && k > 0)
	{
		Node* slow = head;
		Node* fast = head;		
		int count = 1;
		while (count < k)
		{
			if (fast != nullptr)
			{
				fast = fast->next;				
				count++;
			}			
		}
		if (fast == nullptr)
		{
			count--;
		}

		if (k <= count)
		{
			while (fast != tail)
			{
				fast = fast->next;
				slow = slow->next;
			}
			returnNode = slow;
		}
	}
	return returnNode;
}
