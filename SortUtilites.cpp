#include "SortUtilites.h"
#include <iostream>

void SortUtilites::BubbleSort(std::vector<Node*>& unsortedVector)
{
	for (int i = unsortedVector.size() - 1; i >0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (unsortedVector[j]->value > unsortedVector[j + 1]->value)
			{
				Swap(unsortedVector, j, j + 1);
			}
		}
	}

	//int k = unsortedVector.size();
	//int l = k;
	//if (k <= 1) return;

	//while (l > 0)
	//{
	//	for (int i = 0; i < l-1; i++)
	//	{
	//		Node* currentA = unsortedVector[i];
	//		Node* currentB = unsortedVector[i + 1];
	//		//which ever item is bigger swap
	//		if (currentA->value > currentB->value)
	//		{
	//			Swap(unsortedVector, i, i + 1);
	//		}
	//	}
	//	l--;
	//}
}

void SortUtilites::SelectionSort(std::vector<Node*>& unsortedVector)
{
	int indexThatGoesHere = 0;
	int i = 0;
	int max = unsortedVector.size();
	while (i < max-1)
	{
		indexThatGoesHere = i;
		for (int j = i+1; j < max; j++)
		{
			indexThatGoesHere = unsortedVector[j]->value < unsortedVector[indexThatGoesHere]->value ? j : indexThatGoesHere;
		}
		if (i != indexThatGoesHere)
		{
			Swap(unsortedVector, indexThatGoesHere, i);
		}
		i++;
	}
}



void SortUtilites::Swap(std::vector<Node*>& vectorToOperateOn, int indexA, int indexB)
{
	Node* temp = vectorToOperateOn[indexA];
	vectorToOperateOn[indexA] = vectorToOperateOn[indexB];
	vectorToOperateOn[indexB] = temp;
}

void SortUtilites::Merge(int array[], int leftIndex, int midIndex, int rightIndex)
{
	int leftSize = midIndex - leftIndex + 1;
	int rightSize = rightIndex - midIndex;

	int* leftTempArray = new int[leftSize];
	int* rightTempArray = new int[rightSize];

	//copy elements
	for (int i = 0; i < leftSize; i++)
	{
		leftTempArray[i] = array[leftIndex + i];
	}

	for (int i = 0; i < rightSize; i++)
	{
		rightTempArray[i] = array[midIndex + 1 + i];
	}

	int i = 0; int j = 0; int k = leftIndex;
	while (i < leftSize && j < rightSize)
	{
		if (leftTempArray[i] <= rightTempArray[j])
		{
			array[k++] = leftTempArray[i++];
		}
		else
		{
			array[k++] = rightTempArray[j++];
		}
	}

	//remaining elements
	while (i < leftSize)
	{
		array[k++] = leftTempArray[i++];
	}
	while (j < rightSize)
	{
		array[k++] = rightTempArray[j++];
	}

	delete[] leftTempArray;
	delete[] rightTempArray;
}

void SortUtilites::MergeSort(int array[], int leftIndex, int rightIndex)
{
	//call for left
	//call for right
	if (leftIndex >= rightIndex) 
	{ 
		return; 
	}
	int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
	MergeSort(array, leftIndex, midIndex);
	MergeSort(array, midIndex + 1, rightIndex);
	Merge(array, leftIndex, midIndex, rightIndex);

}

void SortUtilites::QuickSort(int array[], int lowIndex, int endIndex)
{
	if (lowIndex >= endIndex) return;
	int pivot = QuickSortPivot(array, lowIndex, endIndex);
	QuickSort(array, lowIndex, pivot - 1);
	QuickSort(array, pivot+1, endIndex);	
}

int SortUtilites::QuickSortPivot(int array[], int pivotIndex, int endIndex)
{	
	int swapIndex = pivotIndex;
	for (int i = pivotIndex + 1; i <= endIndex; i++)
	{
		if (array[i] < array[pivotIndex])
		{
			swapIndex++;
			//swap 
			QuickSortSwap(array, i, swapIndex);
		}
	}
	QuickSortSwap(array, pivotIndex, swapIndex);
	return swapIndex;
}

void SortUtilites::QuickSortSwap(int array[], int firstIndex, int secondIndex)
{
	int i = array[firstIndex];
	array[firstIndex] = array[secondIndex];
	array[secondIndex] = i;
}

