#include "InterviewQuestionRuner.h"
#include <vector>
#include <iostream>

//Vector: Remove Element ( ** Interview Question) Problem # 1
void removeElement(std::vector<int>& nums, int val) 
{
	//int originalSize = nums.size();
	//int newSize = originalSize;
	//int shiftCount = 0;
	//for (int i = 0; i < originalSize; i++)
	//{
	//	if(nums[i] == val)
	//	{
	//		newSize--;
	//		shiftCount++;
	//	}
	//	else
	//	{
	//		nums[i - shiftCount] = nums[i];
	//	}
	//}	
	//nums.resize(newSize);

	int i = 0;
	for(int j = 0; j < nums.size(); j++)
	{
		if(nums[j] != val)
		{
			nums[i++] = nums[j];
		}
	}
	nums.resize(i);

}

void PrintVector(std::vector<int> inputVector, std::string leadingComment = "")
{	
	std::cout << leadingComment;
	if (inputVector.size() == 0)return;
	for (int i = 0; i < inputVector.size()-1; i++)
	{
		std::cout << inputVector[i] << ", ";
	}
	std::cout << inputVector[inputVector.size() - 1] << "\n";
}

void InterviewQuestionRuner::Run()
{
	std::vector<int> problem1 = { 3,3,1 };// { 3, 2, 3, 6, 3, 4, 5, 3 };
	PrintVector(problem1, "Problem 1 Before\n");
	removeElement(problem1, 3);
	PrintVector(problem1, "Problem 1 After\n");
}

