#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H 1

#include <iostream>
#include <vector>

using namespace std;

typedef string Elem;

class DNode {
    private:
        Elem elem;
        DNode* prev;
        DNode* next;
        friend class DLinkedList;
};

class DLinkedList {
    private:
        DNode* header;
        DNode* trailer;
    protected:
        void add(DNode* v, const Elem& e)
        {
            DNode* u = new DNode;
            u->elem = e;
            u->next = v;
            u->prev = v->prev;
            v->prev->next = u;
            v->prev = u;
        }

        void remove(DNode* v)
        {
            DNode* u = v->prev;
            DNode* w = v->next;
            u->next = w;
            w->prev = u;
            delete v;
        }

    public:
        DLinkedList()
        {
            header = new DNode;
            trailer = new DNode;
            header->next = trailer;
            trailer->prev = header;
        }

        ~DLinkedList()
        {
            while(!empty() ) removeFront();
            delete header;
            delete trailer;
        }

        bool empty() const
        {
            return header->next == trailer;
        }

        const Elem& front() const
        {
            return header->next->elem;
        }

        const Elem& back() const
        {
            return trailer->prev->elem;
        }

        void addFront(const Elem& e)
        {
            add(header->next, e);
        }

        void addBack(const Elem& e)
        {
            add(trailer, e);
        }

        void removeFront()
        {
            remove(header->next);
        }

        void removeBack()
        {
            remove(trailer->prev);
        }
};

#endif
