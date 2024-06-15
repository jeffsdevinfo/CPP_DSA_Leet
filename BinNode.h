#pragma once
class BinNode
{
public:
	int value;
	BinNode* left;
	BinNode* right;

	BinNode(int in_value)
	{
		value = in_value;
		left = right = nullptr;
	}
};

