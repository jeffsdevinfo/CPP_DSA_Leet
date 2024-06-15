#pragma once
#include "BaseRunner.h"
#include "Heap.h"
#include <iostream>

class HeapRunner : public BaseRunner
{
public:
	void Run()
	{
		Heap<int> heap;
		heap.Push(5);
		heap.Push(1);
		heap.Push(4);
		heap.Push(22);
		heap.Push(94);
		heap.Push(3);
		int* current = heap.Poll();
		while (current != nullptr)
		{
			std::cout << *current << ", ";
			current = heap.Poll();
		}

	}
};