#include "DoublyLinkedListRunner.h"

void PrintNode(DoublyNode* nodeToPrint, int index)
{
	if (nodeToPrint != nullptr)
	{
		std::cout << "\nFound Node at index: " << index << " with value: " << nodeToPrint->value;
	}
	else
	{
		std::cout << "\nNode was nullptr at index " << index;
	}
}

void DoublyLinkedListRunner::Run()
{
	DoublyLinkedList* dLLTester = new DoublyLinkedList(15);

	dLLTester->append(45);
	dLLTester->append(82);
	dLLTester->append(21);
	dLLTester->printList();
	dLLTester->deleteLast();
	dLLTester->printList();
	dLLTester->prepend(8383);
	dLLTester->prepend(100);
	dLLTester->printList();
	dLLTester->deleteFirst();;
	dLLTester->printList();

	DoublyNode* foundNode = dLLTester->get(0);
	PrintNode(foundNode, 0);
	foundNode = dLLTester->get(dLLTester->getLengthValue()-1);
	PrintNode(foundNode, dLLTester->getLengthValue() - 1);
	foundNode = dLLTester->get(1000);
	PrintNode(foundNode, 1000);


	std::cout << "\n Prepend 474";
	dLLTester->insert(0, 474);
	dLLTester->printList();
	std::cout << "\n Append 8390";
	dLLTester->insert(dLLTester->getLengthValue(), 8390);
	dLLTester->printList();
	std::cout << "\n Set index 1 value to 817";
	dLLTester->set(1, 817);
	dLLTester->printList();
	std::cout << "\n Set last index value to 817";
	dLLTester->set(dLLTester->getLengthValue()-1, 817);
	dLLTester->printList();
	std::cout << "\n Delete index 0";
	dLLTester->deleteNode(0);
	dLLTester->printList();
	std::cout << "\n Delete last element";
	dLLTester->deleteNode(dLLTester->getLengthValue()-1);
	dLLTester->printList();	

	std::cout << "\n Delete index 1 element";
	dLLTester->deleteNode(1);
	dLLTester->printList();
}
