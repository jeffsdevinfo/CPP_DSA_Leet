#pragma once
#include "NodeTemplate.h"
#include <iostream>
template <typename TData>
class QueueTemplate
{
private:
	NodeTemplate<TData>* first;
	NodeTemplate<TData>* last;
	int length = 0;

public:
	QueueTemplate(TData value)
	{
		first = last = new NodeTemplate<TData>(value);
	}
	QueueTemplate()
	{
		first = last = nullptr;
	}

	void Enqueue(TData value)
	{
		NodeTemplate<TData>* newT = new NodeTemplate<TData>(value);
		if (first == nullptr)
		{
			first = last = newT;
		}
		else
		{
			last->next = newT;
			last = newT;
		}
		length++;
	}

	TData* Dequeue()
	{
		TData* dataToReturn = nullptr;
		if (length > 0)
		{
			if (first == last)
			{
				dataToReturn = new TData(first->value);
				delete first;
				first = last = nullptr;
			}
			else
			{
				dataToReturn = new TData(first->value);				
				NodeTemplate<TData>* temp = first;
				first = first->next;
				delete temp;
				temp = nullptr;
			}
		}
		length--;
		return dataToReturn;
	}

	void PrintQueue()
	{
		NodeTemplate<TData>* current = first;
		while (current != nullptr)
		{
			std::cout << current->value << " ";
			current = current->next;
		}
	}

	int getLength()
	{
		return length;
	}
};

