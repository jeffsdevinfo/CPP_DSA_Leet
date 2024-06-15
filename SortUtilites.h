#pragma once
#include "Node.h"
#include <vector>

class SortUtilites
{
public:
	static void BubbleSort(std::vector<Node*>& unsortedVector);
	static void SelectionSort(std::vector<Node*>& unsortedVector);
	static void Swap(std::vector<Node*>& vectorToOperateOn, int indexA, int indexB);
	static void Merge(int array[], int leftIndex, int midIndex, int rightIndex);
	static void MergeSort(int array[], int leftIndex, int rightIndex);
	static void QuickSort(int array[], int lowIndex, int endIndex);
	static int QuickSortPivot(int array[], int pivotIndex, int endIndex);
	static void QuickSortSwap(int array[], int firstIndex, int secondIndex);
};

