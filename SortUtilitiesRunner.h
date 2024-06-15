#pragma once
#include "BaseRunner.h"
#include "SortUtilites.h"
#include <vector>

class SortUtilitiesRunner : public BaseRunner
{
public:
	void Run() override;
	void Print(std::vector<Node*> inputVector);
	void Print(int array[], int size);
};

