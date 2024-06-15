#include "QueueTemplateRunner.h"

void QueueTemplateRunner::Run()
{
	QueueTemplate<int>* newQueueTemplate = new QueueTemplate<int>(25);
	newQueueTemplate->Enqueue(5);
	newQueueTemplate->Enqueue(100);
	newQueueTemplate->Enqueue(1);
	newQueueTemplate->Enqueue(7);
	newQueueTemplate->Enqueue(80);
	newQueueTemplate->Enqueue(150);
	newQueueTemplate->PrintQueue();
}
