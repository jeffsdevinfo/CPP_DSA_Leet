#include "BinTreeRunner.h"

void BinTreeRunner::Run()
{
	BinTree* newBinTree = new BinTree();
	newBinTree->insert(25);
	newBinTree->insert(15);
	newBinTree->insert(100);
	newBinTree->insert(10);
	newBinTree->insert(20);
	newBinTree->insert(50);
	newBinTree->insert(180);
	newBinTree->insert(5);
	newBinTree->insert(12);
	newBinTree->insert(16);
	newBinTree->insert(24);
	newBinTree->insert(35);
	newBinTree->insert(65);
	newBinTree->insert(150);

	std::cout << "\nPrinting PreOrder \n";
	newBinTree->printTree(BinTree::TreeOrder::PreOrder);

	std::cout << "\nPrinting InOrder \n";
	newBinTree->printTree(BinTree::TreeOrder::InOrder);

	std::cout << "\nPrinting PostOrder \n";
	newBinTree->printTree(BinTree::TreeOrder::PostOrder);

	std::cout << "\nPrinting LevelOrder \n";
	newBinTree->printTree(BinTree::TreeOrder::LevelOrder);
}
