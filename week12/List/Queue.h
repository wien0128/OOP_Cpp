#ifndef QUEUE_H
#define QUEUE_H
#include "List.h"

class Queue : private List {
public:
    void enqueue(int n);
    int dequeue();
    void empty() const;
};

#endif