#include "QueueRunner.h"

void QueueRunner::Run()
{
	Queue* newQueue = new Queue(44);
	std::cout << "\n\nPrintQueue\n";
	newQueue->printQueue();
	std::cout << "\n\nEnqueue: " << 25;
	newQueue->enqueue(25);
	std::cout << "\n\nPrintQueue\n";
	newQueue->printQueue();
	std::cout << "\n\nEnqueue: " << 300;
	newQueue->enqueue(300);
	std::cout << "\n\nPrintQueue\n";
	newQueue->printQueue();
	int value = newQueue->dequeue();
	std::cout << "\n\tValue from dequeue: " << value;
	std::cout << "\n\nPrintQueue\n";
	newQueue->printQueue();
}
