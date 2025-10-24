#include <iostream>
#include <vector>
#include "DLinkedList.h"
#include "../../queue/QueueException.h"

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

LinkedDeque::LinkedDeque() : D(), n(0)
{

}

int LinkedDeque::size() const
{
    return n;
}

bool LinkedDeque::empty() const
{
    return n == 0;
}

const Elem& LinkedDeque::front() const throw(QueueEmpty)
{
    if(empty())
        throw QueueEmpty("front of empty LinkedDeque.");
    return D.front();
}

const Elem& LinkedDeque::back() const throw(QueueEmpty)
{
    if(empty())
        throw QueueEmpty("back of empty LinkedDeque.");
    return D.back();
}

void LinkedDeque::insertFront(const Elem& e)
{
    D.addFront(e);
    n++;
}

void LinkedDeque::insertBack(const Elem& e)
{
    D.addBack(e);
    n++;
}

void LinkedDeque::removeFront() throw(QueueEmpty)
{
    if(empty())
        throw QueueEmpty("removeFront of empty LinkedDeque.");
    D.removeFront();
    n--;
}

void LinkedDeque::removeBack() throw(QueueEmpty)
{
    if(empty())
        throw QueueEmpty("removeBack of empty LinkedDeque.");
    D.removeBack();
    n--;
}