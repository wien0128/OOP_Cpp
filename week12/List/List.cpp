#include "List.h"
List::List() : head(nullptr), tail(nullptr), size(0) {}

List::~List() {
    while(head) {
        ListNode *tmp = head->next;
        delete head;
        head = tmp;
    }
}

void List::pushFront(int value) {
    ListNode *node = new ListNode(value);
    if (!head) 
        head = tail = node;
    else 
    {
        head->prev = node;
        node->next = head;
        head = node;
    }
    size++;
}

void List::pushBack(int value) {
    ListNode *node = new ListNode(value);
    if (!head) 
        head = tail = node;
    else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
    size++;
}

int List::popFront() {
    if (!head) throw "Empty List";
    int value = head->value;
    ListNode *del = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete del;
    size--;
    return value;
}

int List::popBack() {
    if (!tail) throw "Empty List";
    int value = tail->value;
    ListNode *del = tail;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    delete del;
    size--;
    return value;
}

int List::length() const {
    return size;
}