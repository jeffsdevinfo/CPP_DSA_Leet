#pragma once
#include <vector>
#include <memory>

template <typename TData>
class HeapNode
{
private:
	TData* _value;

public:
	//HeapNode(TData data)
	//{
	//	_value = new TData(data);
	//}

	// copy constructor
	HeapNode(const TData& refData)
	{
		_value = new TData(refData);
	}

	bool operator==(const HeapNode<TData>& other) const
	{
		return *_value == *(other._value);
	}

	bool operator!=(const HeapNode<TData>& other) const
	{
		return !(*_value == *(other._value));
	}

	bool operator>(const HeapNode<TData>& other) const
	{
		return *_value > *(other._value);
	}

	bool operator<(const HeapNode<TData>& other) const
	{
		return *_value < *(other._value);
	}

	TData* GetData() { return _value; }
};

template <typename TData>
class Heap
{
private:
	std::vector<std::unique_ptr<HeapNode<TData>>> _heap;

public:
	enum HeapType {Min, Max};
	HeapType HeapTypeProperty = HeapType::Min;

	Heap(HeapType heapType = HeapType::Min)
	{				
		HeapTypeProperty = heapType;
	}	

	int GetLeft(int parentIndex) { return (parentIndex * 2) + 1; }
	int GetRight(int parentIndex) { return (parentIndex * 2) + 2; }
	int GetParent(int childIndex) { return (childIndex - 1) / 2; }
	bool ValidIndex(int index) { return _heap.size() > index; }

	void Push(const TData& data)
	{		
		_heap.emplace_back(std::make_unique<HeapNode<TData>>(data));
		if (_heap.size() > 1)
		{
			HeapifyUp((int)(_heap.size() - (size_t)1));
		}
	}

	void HeapifyUp(int index)
	{
		if (HeapTypeProperty == HeapType::Min)
		{
			//do min down
			if (ValidIndex(index))
			{
				int parentIndex = GetParent(index);
				while (ValidIndex(parentIndex))
				{
					if (*_heap[parentIndex] > *_heap[index])
					{
						SwapIndexes(index, parentIndex);
						index = parentIndex;
						if (index == 0) break;
						parentIndex = GetParent(index);
					}
					else
					{
						break;
					}
				}
			}
		}
		else
		{
			//do max down
			if (ValidIndex(index))
			{
				int parentIndex = GetParent(index);
				while (ValidIndex(parentIndex))
				{
					if (_heap[parentIndex] < _heap[index])
					{
						SwapIndexes(index, parentIndex);
						index = parentIndex;
						parentIndex = GetParent(index);
					}
				}
			}
		}
	}

	TData* Poll()
	{
		TData* returnData = nullptr;		
		if (_heap.size() > 0)
		{
			returnData = _heap[0]->GetData();
			if (_heap.size() > 1)
			{
				_heap[0] = std::move(_heap[_heap.size() - 1]);
				_heap.pop_back();
				if (_heap.size() > 1)
				{
					HeapifyDown();
				}
			}
			else
			{
				_heap.pop_back();
			}			
		}
		return returnData;
	}

	void HeapifyDown()
	{
		int index = 0;
		int comparisonIndex = 0;
		if (HeapTypeProperty == HeapType::Min)
		{
			//do min down
			int leftChild = GetLeft(index);
			int rightChild = GetRight(index);
			while (ValidIndex(leftChild))
			{
				comparisonIndex = leftChild;
				if (ValidIndex(rightChild) && *_heap[rightChild] < *_heap[comparisonIndex])
				{
					comparisonIndex = rightChild;
				}
				if (*_heap[index] > *_heap[comparisonIndex])
				{
					SwapIndexes(index, comparisonIndex);
					index = comparisonIndex;
					leftChild = GetLeft(index);
					rightChild = GetRight(index);
				}
			}
		}
		else
		{
			//do max down
		}
	}
	
	void SwapIndexes(int indexA, int indexB)
	{
		std::swap(_heap[indexA], _heap[indexB]);
	}
};

