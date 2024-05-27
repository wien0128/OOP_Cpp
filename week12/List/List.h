#ifndef LIST_H
#define LIST_H

class ListNode;
class List {
    ListNode *head;
    ListNode *tail;
    int size;
public:
    List();
    ~List();
    void pushFront(int);
    void pushBack(int);
    int popFront();
    int popBack();
    int length() const;
};
class ListNode {
    int value;
    ListNode *next;
    ListNode *prev;
public:
    friend List;
    ListNode(int value = 0) 
    :value(value), next(nullptr), prev(nullptr) {}
};

#endif