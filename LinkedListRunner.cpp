#include "LinkedListRunner.h"

void PrintANode(Node* temp, int index = -1 )
{
	if (temp != nullptr) {
		std::cout << "\nValue at index " << index << " = " << temp->value;
	}
}

void LinkedListRunner::Run()
{
	std::cout << "LinkedListRunner run";
	LinkedList* ll = new LinkedList(1);	
	ll->Append(2);
	ll->Append(3);

	//Node* middle = ll->findMiddleNode();
	//PrintANode(middle);	
	//middle = ll->findMiddleNode();
	//PrintANode(middle);
	/*std::cout << "\n Has loop (false) = " << ll->hasLoop(false);
	std::cout << "\n Has loop (true) = " << ll->hasLoop(true);
	std::cout << "\n Has loop (true) = " << ll->hasLoop(false);*/
	Node* temp = ll->findKthFromEnd(0);
	int val = ll->getLength() - 0;
	if (temp != nullptr) {
		PrintANode(temp, val);
	}
	else
	{
		std::cout << "\nDid not find value";
	}
	delete(ll);
}
