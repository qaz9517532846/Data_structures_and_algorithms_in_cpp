#include <iostream>
#include <vector>
#include "CircleList.h"
#include "../QueueException.h"

typedef string Elem;

class LinkedQueue {
    public:
        LinkedQueue();
        int size() const;
        bool empty() const;
        const Elem& front() const throw(QueueEmpty);
        void enqueue(const Elem &e);
        void dequeue() throw(QueueEmpty);
    private:
        CLinkedList C;
        int n;
};