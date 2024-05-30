#include "List.h"
#include "Queue.h"

void Queue::enqueue(int n)
{
    this->pushFront(n);
}

int Queue::dequeue()
{
    return this->popFront();
}

bool Queue::empty() const
{
    return this->length();
}