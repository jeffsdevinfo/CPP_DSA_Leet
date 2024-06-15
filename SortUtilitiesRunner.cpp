#include "SortUtilitiesRunner.h"
#include <vector>
#include <iostream>

void SortUtilitiesRunner::Run()
{
	//std::vector<Node*> myVector;
	//myVector.push_back(new Node(4));
	//myVector.push_back(new Node(22));
	//myVector.push_back(new Node(1));
	//myVector.push_back(new Node(0));
	//myVector.push_back(new Node(33));
	//myVector.push_back(new Node(400));
	//myVector.push_back(new Node(28));
	//myVector.push_back(new Node(39));
	//myVector.push_back(new Node(3));
	////SortUtilites::BubbleSort(myVector);
	//std::cout << "\nSelection Sort example\n";
	//SortUtilites::SelectionSort(myVector);
	//Print(myVector);

	//std::cout << "\nMerge Sort example\n";
	//int myArray[] = { 1,3,7,8,2,4,5 };
	//int size = sizeof(myArray) / sizeof(myArray[0]);	
	//SortUtilites::MergeSort(myArray, 0, size - 1);
	//Print(myArray, size);

	std::cout << "\Quick Sort example\n";
	int myArraQS[] = {8,1,21,15,13,9,3 };
	int size = sizeof(myArraQS) / sizeof(myArraQS[0]);
	//int value = SortUtilites::QuickSortPivot(myArraQS, 0, size - 1);
	//std::cout << value << "\n";
	SortUtilites::QuickSort(myArraQS, 0, size - 1);
	Print(myArraQS, size);

	//int rightIndex = size - 1;
	//int mid = (size / 2) ;
	

	//SortUtilites::(myArray, 0, mid, rightIndex);


}

void SortUtilitiesRunner::Print(std::vector<Node*> inputVector)
{
	for (int i = 0; i < inputVector.size(); i++)
	{
		std::cout << inputVector[i]->value << ", ";
	}
}

void SortUtilitiesRunner::Print(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << array[i] << ", ";
	}
}
