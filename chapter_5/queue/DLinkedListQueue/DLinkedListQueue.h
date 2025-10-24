#include <iostream>
#include <vector>
#include "DLinkedList.h"
#include "../QueueException.h"

typedef string Elem;

class LinkedDeque {
    public:
        LinkedDeque();
        int size() const;
        bool empty() const;
        const Elem& front() const throw(QueueEmpty);
        const Elem& back() const throw(QueueEmpty);
        void insertFront(const Elem& e);
        void insertBack(const Elem& e);
        void removeFront() throw(QueueEmpty);
        void removeBack() throw(QueueEmpty);
    private:
        DLinkedList D;
        int n;
};