#include "StackRunner.h"

void StackRunner::Run()
{
	Stack* newStack = new Stack(44);
	newStack->getTop();
	newStack->getHeight();
	newStack->push(373);
	std::cout << "\n\nPrintStack\n";
	newStack->printStack();
	newStack->pop();
	std::cout << "\n\nPrintStack\n";
	newStack->printStack();
}
