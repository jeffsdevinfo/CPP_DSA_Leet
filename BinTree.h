#pragma once
#include <iostream>
#include "BinNode.h"
#include "QueueTemplate.h"
class BinTree
{
public:
	BinNode* root;
	BinTree()
	{
		root = nullptr;
	}
	enum TreeOrder {PreOrder, InOrder, PostOrder, LevelOrder};
	bool insert(int value);
	void printTree(TreeOrder order, BinNode* current = nullptr);
	void BFS();

private:
	void levelOrder();
};

